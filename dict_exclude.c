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

#define DICT_EXCLUDE_BACKREF_CNT    10

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(dict_exclude_lexize);


Datum
dict_exclude_lexize(PG_FUNCTION_ARGS)
{
  char     *in = (char *) PG_GETARG_POINTER(1);
  TSLexeme   *res;
  res = palloc0(sizeof(TSLexeme) * 3);

  /* dictionary_load(dictionary_fullpath("data/kata-dasar.txt")); */

  res[0].lexeme = pnstrdup(in, PG_GETARG_INT32(2)) ;
  /* stem_singular_word(res[0].lexeme, &(res[1].lexeme)); */
  res[1].lexeme = pnstrdup("hohoman",8);


  PG_RETURN_POINTER(res);
}
