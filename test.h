#ifndef TEST_H
#  define TEST_H

#  define max 3333
#define nelems(x) sizeof(x)/sizeof(x[0])
/* # undefine nelems */

/* #define paste(one, two) one ## two */
/*
 * Usage:
 *
 *   paste(foo, 1)
 *
 * Expansion:
 *
 *   foo1
 */

#  if !defined(FOO)
#    define FOO 123
#  endif

#endif