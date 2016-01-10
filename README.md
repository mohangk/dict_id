#dict_id

## Introduction

Stemming dictionary for Postgres that uses [cSastrawi](https://github.com/mohangk/c_sastrawi) .

## Status

Alpha version. Should only be used if you are keen on helping with the development.

## Install

### Install a standalone postgres instance

```
cd ~
$ curl https://ftp.postgresql.org/pub/source/v9.4.4/postgresql-9.4.4.tar.bz2 | bzip2 -d | tar x
$ cd postgresql-9.4.4
$ ./configure --enable-cassert --enable-debug CFLAGS="-ggdb"
$ make
$ sudo make install
```

Init the database

``` 
$ sudo chown $(whoami) /usr/local/pgsql
$ /usr/local/pgsql/bin/initdb -D /usr/local/pgsql/data
````

Start the server,

```
$ /usr/local/pgsql/bin/pg_ctl -D /usr/local/pgsql/data -l /usr/local/pgsql/data/postmaster.log start
```

Add new psql binary to path

```
$ export PATH=/usr/local/pgsql/bin:$PATH
```

### Install the extension

In the extension dir run

```
$ make && sudo make install
```

Create and connect to a test database

```
$ /usr/local/pgsql/bin/createdb test
$ /usr/local/pgsql/bin/psql test
```


Within the console

```
test=# create extension dict_id;
CREATE EXTENSION
```

Test the extension

```
test=# select ts_lexize('dict_id','bertapa'); 
 ts_lexize
-----------
 {tapa}
(1 row)
```


