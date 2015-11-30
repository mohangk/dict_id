-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION dict_id" to load this file. \quit

-- CREATE FUNCTION dict_id_init(internal)
--         RETURNS internal
--         AS 'MODULE_PATHNAME'
--         LANGUAGE C STRICT;

CREATE FUNCTION dict_id_lexize(internal, internal, internal, internal)
        RETURNS internal
        AS 'MODULE_PATHNAME'
        LANGUAGE C STRICT;

CREATE TEXT SEARCH TEMPLATE dict_id_template (
        LEXIZE = dict_id_lexize
	      --INIT   = dict_id_init
);

CREATE TEXT SEARCH DICTIONARY dict_id (
	TEMPLATE = dict_id_template
);

COMMENT ON TEXT SEARCH DICTIONARY dict_id IS 'dictionary for stemming Bahasa Indonesia words';
