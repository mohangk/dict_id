# dict_id/Makefile
MODULE_big = dict_id
OBJS = dict_id.o $(WIN32RES)
PG_CPPFLAGS = -I/usr/local/include -I/Users/mohangk/Workspace/c_sastrawi/src
SHLIB_LINK = -L/usr/local/lib -lpcre2-8 libs/libsastrawi.a


EXTENSION = dict_id
DATA = dict_id--1.0.sql dict_id--unpackaged--1.0.sql
PGFILEDESC = "dict_id - stemming dictionary for Bahasa Indonesia"

REGRESS = dict_id

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
