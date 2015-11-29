# dict_exclude/Makefile
MODULE_big = dict_exclude
OBJS = dict_exclude.o $(WIN32RES)
PG_CPPFLAGS = -I/usr/local/include -I/Users/mohangk/Workspace/c_sastrawi/src

EXTENSION = dict_exclude
DATA = dict_exclude--1.0.sql dict_exclude--unpackaged--1.0.sql
PGFILEDESC = "dict_exclude - add-on dictionary template for full-text search"

REGRESS = dict_exclude

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
CPPFLAGS = -I/usr/local/include
