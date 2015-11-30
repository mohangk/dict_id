/*-------------------------------------------------------------------------
 *
 * A postgresql text search dictionary for stop words based on regular expressions.
 * Based largely on the excellent dict_int example in postgresql contrib.
 * Offered under same license as Postgresql.
 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"
#include "fmgr.h"
#include "tsearch/ts_public.h"
#include "includes/libsastrawi.h"

#define DICT_EXCLUDE_BACKREF_CNT    10

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(dict_id_lexize);


Datum
dict_id_lexize(PG_FUNCTION_ARGS)
{
  char     *in = (char *) PG_GETARG_POINTER(1);
  TSLexeme   *res;
  res = palloc0(sizeof(TSLexeme) * 2);
  char *stemmed;

  dictionary_load(dictionary_fullpath("data/kata-dasar.txt"));

  stem_singular_word(in, &stemmed);
  res[0].lexeme = pnstrdup(stemmed,strlen(stemmed));

  PG_RETURN_POINTER(res);
}
