## The process of moving the database:

1) First of all, I imported the data from `restore.sql` and created a new data base `dvdrental` by doing so:
```console
$ psql -U postgres
postgres=# CREATE DATABASE dvdrental;
postgres=# \q
$ psql -U postgres -d dvdrental -f restore.sql
```

2) Then, I converted the SQL database into JSON-format and stored the data in text files in folder `jsons`.

3)  I wrote a python script `script.py` that reads all text files in folder `jsons` and create a new Mongo collection according to the file new, and insterts all units in the txt file into our Mongo database:
```console
documents = text.split('\n')
    for document in documents:
        if document == '':
            continue
        dict = json.loads(document)
        collection.insert_one(dict)
```

##  The adjustments that were necessary for the new database:

The only adjustment was needed for the new database was the empty columns that might appear in SQL in some rows. In Mongodb, all the field should have some values, and the data fields inside one row is dynamic not fixed.


## Comments on the performance of the queries:

Queries 1 and 3 are working perfectly in a fast runtime. Query 2 was noticeably slow because of the big number of nested searching operations made to find some document in another collection.
