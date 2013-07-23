#ifndef TEST_H
#  define TEST_H

#define max 3333
#define nelems(x) sizeof(x)/sizeof(x[0])
#define MAX_FILE_CONTENT 9999
#define MAX_LINE_LENGTH 9999
#define frand() ((double) rand() / (RAND_MAX + 1.0))

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

#if !defined(FOO)
#  define FOO 123
#endif

#endif