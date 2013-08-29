#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sqlite3 import dbapi2 as s
import jinja2


def getData():
    print("1. getting data")
    with s.connect("data.db") as conn:
        cur = conn.cursor()
        cur.execute("SELECT * FROM languages")
        result = cur.fetchall()
        cur.close()
    return result


def saveJinjaTemplate(data):
    print ("2. saving templates")
    template_loader = jinja2.FileSystemLoader(".")
    template_env = jinja2.Environment(loader=template_loader)
    TEMPLATE_FILE = "templates/simple.html"
    template = template_env.get_template(TEMPLATE_FILE)
    for i in data:
        vars = {
            "id": i[0],
            "name": i[1],
            "description": i[2]
        }
        out = template.render(vars)
        filename = "output/id_" + ("%s" % i[0]) + ".html"
        file = open(filename, 'w')
        file.write(out.encode('utf-8'))
        file.close()
        print("2.%s saved file for [%s]" % (i[0], i[1]))


def createIndex(data):
    print("3. creating index")
    template_loader = jinja2.FileSystemLoader(".")
    template_env = jinja2.Environment(loader=template_loader)
    urls = []
    for i in data:
        urls.append("id_" + ("%s" % i[0]) + ".html")
    TEMPLATE_FILE = "templates/simple_index.html"
    template = template_env.get_template(TEMPLATE_FILE)    
    out = template.render({"urls": urls})
    filename = "output/index.html"
    file = open(filename, 'w')
    file.write(out.encode('utf-8'))
    file.close()

if __name__ == "__main__":
    data = getData()
    saveJinjaTemplate(data)
    createIndex(data)
