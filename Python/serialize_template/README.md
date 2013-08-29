serialize-template   
===================

Extract data from a database and parse the records with a Jinja2
template and generate the output files and a index file.

Start DB
--------

```
  $ sqlite3 -init data.sql data.db
  -- Loading resources from data.sql

  SQLite version 3.7.17 2013-05-20 00:56:22
  Enter ".help" for instructions
  Enter SQL statements terminated with a ";"
  sqlite> .q
  $
```

