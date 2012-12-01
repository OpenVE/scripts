#!/usr/bin/python
# -*- coding: utf-8 -*-

"""Conversion de archivos CSV del CNE del Registro Electoral Permanente
a SQL
"""
__version__ = '0.3'

import argparse
import csv
from sqlalchemy import create_engine, engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base

# Analisis de pase de parametros
parser = argparse.ArgumentParser()
parser.add_argument("input", help="Fichero CSV del CNE")
parser.add_argument("type",
                    choices=["centros", "electores"],
                    help="Tipo de fichero de entrada")
args = parser.parse_args()

# Modelos
Base = declarative_base()
# TODO: Colocar db_uri como parametro en linea de comando,
# hacer uso de sqlalachemy.engine.url.URL para parsing de
# argumentos
db_uri = "postgresql+psycopg2:///cne"
engine = create_engine(db_uri, echo=False)


class Centro(Base):
    __tablename__ = 'centros'

    id = Column(Integer, primary_key=True)
    cod_centro = Column(Integer)
    tipo = Column(Integer)  # TODO: En realidad debe ser un ForeignKey
    cod_estado = Column(Integer)  # TODO: En realidad debe ser un ForeignKey
    cod_municipio = Column(Integer)  # TODO: En realidad debe ser un ForeignKey
    cod_parroquia = Column(Integer)  # TODO: En realidad debe ser un ForeignKey
    nombre_centro = Column(String(128))
    direccion_centro = Column(String(256))
    centro_nuevo = Column(Integer)

    def __repr__(self):
        return "<Centro('%s', '%s', '%s', '%s')>" % (self.cod_estado,
                                                     self.cod_municipio,
                                                     self.cod_parroquia,
                                                     self.nombre_centro)


class Elector(Base):
    __tablename__ = 'electores'

    id = Column(Integer, primary_key=True)
    nacionalidad = Column(String(1))
    cedula = Column(Integer)
    primer_apellido = Column(String(32))
    segundo_apellido = Column(String(32), nullable=True)
    primer_nombre = Column(String(32))
    segundo_nombre = Column(String(32), nullable=True)
    codigo_centro = Column(Integer)

    def __repr__(self):
        return "<Elector('%s', '%s', '%s', '%s')>" % (self.cedula,
                                                      self.primer_apellido,
                                                      self.primer_nombre,
                                                      self.codigo_centro)

Base.metadata.create_all(engine)


def UnicodeDictReader(utf8_data, **kwargs):
    csv_reader = csv.DictReader(utf8_data, **kwargs)
    for row in csv_reader:
        yield dict([(key, unicode(value, 'utf-8'))
                    for key, value in row.iteritems()])


with open(args.input, 'rb') as cne_file:
    cne_rows = UnicodeDictReader(cne_file, delimiter=';')
    with engine.begin() as connection:
        table_object = Elector if args.type == 'electores' else Centro
        connection.execute(
            table_object.__table__.insert(),
            [row for row in cne_rows]
        )
    print "Se han insertado los registros"
