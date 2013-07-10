#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "test.h"


/* enum colors { */
/*   RED = 3, */
/*   GREEN, */
/*   BLUE, */
/* }; */

void say() {
  /* char input; */
  /* scanf("%s", &input); */
  /* printf("%s\n", input); */

  /* printf("%s: %d\n", "Co" "lor", GREEN); */

  printf("say");
}

void squeeze(char s[], int c) {
  int i;
  int j;

  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';
}

void doList(char s[]) {
  int i;
  /* for(i = 0; s[i] != '\0'; ++i) { */
  while(s[i] != '\0') {
    i++;
    printf("%s\n", s[i]);
  }
}

int invert(int i) {
  return ~i + 1;
}

/* void enumerate(char enumerable) { */
/*   for (int i = 0; i < 3; ++i) { */
/*     printf("#%d: %s", i, enumerable[i]); */
/*   } */
/* } */

void swapInt(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void listArgv(int argc, char *argv[]) {
  while(--argc > 0) {
    /* printf("%s%s", *++argv, (argc > 1) ? " " : "\n"); */

    /* printf("---> %s\n", *++argv); */

    *++argv;
    if (*argv[0] == '-') {
      printf("++++++++++%s\n", argv[0]);
    } else {
      /* printf("argv: %s\n", *argv); */
      printf("argv: %s %s\n", strstr("foo", *argv) ? "(+)" : "(-)", *argv);
    }
  }
}

void main(int argc, char *argv[]) {
  // printf("Test\n");
  /* say(); */


  /* char enumerable[6] = {'1', '2', '3', '4', '5', '6'}; */
  /* enumerate(enumerable); */


  /* XXX */
  /* char s[] = {'a', 'b', 'c', 'd', 'e', 'f'}; */
  /* char c = 'c'; */
  /* squeeze(s, c); */


  /* XXX */
  /* char s[] = {'a', 'b', 'c', 'd', 'e', 'f'}; */
  /* doList(&s); */


  /* /\* Operations on arrays *\/ */
  /* int numbers[] = {111, 222, 333, 444, 555, 666, */
  /*                  -111, -222, -333, -444, -555, -666}; */
  /* for (int i = 0; i < nelems(numbers); ++i) { */
  /*   printf("%d: %d\n", numbers[i], invert(numbers[i])); */
  /* } */


  /* /\* Bit shifting *\/ */
  /* printf("%d\n", 110011 >> 2); */


  /* /\* Constants *\/ */
  /* printf("Foo: %d\n", FOO); */


  /* /\* Pointer arguments *\/ */
  /* int x = 123; */
  /* int y = 456; */
  /* printf("Before swapping: a = %d, b = %d\n", x, y); */
  /* swapInt(&x, &y); */
  /* printf("After swapping: a = %d, b = %d\n", x, y); */


  /* /\* Pointers to functions *\/ */
  /* int *f();    /\* f: function returning pointer to int *\/ */
  /* int (*pf)(); /\* pf: pointer to function returning int *\/ */

  /* Dispatching command line arguments */
  listArgv(argc, argv);
}
