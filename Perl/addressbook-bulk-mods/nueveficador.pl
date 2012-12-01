#!/usr/bin/env perl

#
# nueveficador.pl -- un sencillo script para convertir los telefonos de tus contactos de Google en 10 digitos
# (C) 2012 Jose Miguel Parrella Romero (bureado) <j@bureado.com>
#
# Software libre bajo los mismos terminos de Perl.
#

use WWW::Google::Contacts;

# Tienes que llenar esto.
my $google = WWW::Google::Contacts->new( username => "", password => "" );

# Especifica tu parámetro de búsqueda aquí.
# Para más, lee: http://search.cpan.org/~merixzon/WWW-Google-Contacts-0.35/lib/WWW/Google/Contacts/Contact.pm#ATTRIBUTES
my @contacts = $google->contacts->search({ given_name => "Diana" });
# my @contacts = $google->contacts->search({ given_name => "Diana", family_name => "Zapata"  }); # otro ejemplo
# my @contacts = $google->contacts->search({}); # todos

foreach my $c ( @contacts ) {
  next unless $c->phone_number;
  foreach my $phone ( @{ $c->phone_number } ) {
    my $new;

    $phone->value =~ s/[^\+\d]//g;

    if ( $phone->value =~ /^0([89]\d+)$/ ) { #08xxxxxxx 09xxxxxxx
      $new = "09$1";
    }

    if ( $phone->value =~ /^\+?593([89]\d+)$/ ) { # 5938xxxxxxx 5939xxxxxxx
      $new = "09$1";
#      $new = "+5939$1"; # este modo preserva el prefijo internacional
    }

    $phone->value($new); $c->update;
  }
}
