#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>
#include <limits.h>
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

  printf("SAY\n");
}

void saySomething(char message[]) {
  printf("%s\n", message);
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

void report(int values[]) {
  int i;
  for(i = 0; i < sizeof(values) - 1; i++) {
    printf("%d\n", values[i]);
  }
}

void reportPoint(int x, int y) {
  printf("point.x: %d; point.y: %d\n", x, y);
}

void testStructures()  {
  /* Simple structure example */
  struct point {
    int x;
    int y;
  } minpt;
  minpt.x = 22;
  minpt.y = 33;
  printf("minpt.x: %d; minpt.y: %d\n", minpt.x, minpt.y);

  struct point pt = { 44, 55 };
  printf("pt.x: %d; pt.y: %d\n", pt.x, pt.y);


  /* Structures can hold pointers to functions */
  struct something {
    /* void foo() { */
    /*   printf("%s", "FOO"); */
    /* }; */
    void (*foo)();
    int bar;
  };
  struct something sth = { &saySomething, 30 };
  sth.foo("BARFOO");
}

void testInput() {
  char c;
  while((c = getchar()) != EOF) {
    putchar('-');
    putchar(c);
  }
}

void testFileAccess(char fileName[]) {
  FILE *filep;
  filep = fopen(fileName, "r");
  char fileContent[MAX_FILE_CONTENT];
  int c;

  if(filep == NULL) {
    fprintf(stderr, "%s\n", "No input file specified.");
    exit(2);
  } else {
    c = getc(filep);

    while((c = getc(filep)) != EOF) {
      putc(c, stdout);
    }

    fclose(filep);
  }
}

void testLineReading(char fileName[]) {
  FILE *fp;
  fp = fopen(fileName, "r");
  char line[MAX_LINE_LENGTH];

  if(fp == NULL) {
    fprintf(stderr, "%s\n", "No input file specified.");
    exit(2);
  } else {
    while(fgets(line, 9999, fp) != NULL) {
      printf("%s", line);
      /* printf("%i\n", strlen(line)); */
    }
    fclose(fp);
  }
}

void testCharacterClassFunctions() {
  char c = 'a';
  int test;
  test = isalpha(c);
  /* test = isupper(c); */
  /* test = islower(c); */
  /* test = isdigit(c); */
  /* test = isalnum(c); */
  /* test = isspace(c); */

  if (test == 0) {
    printf("%s\n", "No.");
  } else if (test > 0) {
    printf("%s\n", "Yes.");
  } else {
    printf("%s\n", "Don't know.");
  }

  printf("%c\n", toupper('a'));
  printf("%c\n", tolower('A'));
}

void testSystemCommand(char command[]) {
  int returnValue = system(command);
  if (&returnValue == NULL) {
    printf("\nReturn value: %i (no error)\n", returnValue);
  } else {
    printf("\nReturn value: %i (error)\n", returnValue);
  }
}


void testArrayIteration(char string[]) {
  int i = 0;
  char c = string[0];

  while (c != '\0') {
    i++;
    printf("-> %c%s\n", c, (isupper(c) > 0) ? " (upper case)" : "");
    c = string[i];
  }
}

void testFiles(char *name)  {
  int i;
  int exists = 0;

  if (access(name, F_OK) != 0) {
    exists = 1;
  }

  FILE *fp = fopen(name, "w");

  if (exists != 0) {
    printf("File `%s' created\n", name);
  }

  printf("File `%s' opened\n", name);

  for (i = 0; i < 500; i++) {
    fprintf(fp, "# %i\n", i);
  }

  fclose(fp);
  printf("File `%s' closed\n", name);

  remove(name);
  printf("File `%s' removed\n", name);
}

void writeCharsToFile(char *name)  {
  FILE *fp = fopen(name, "w");
  int i;

  for (i = 0; i < 400; i++) {
    fputc((char) (((int) '0') + i), fp);
  }

  fclose(fp);
}

void testStreams(char name[])  {
  FILE *fp = fopen(name, "r");
  char c;

  while ((c = getc(fp)) != EOF) {
    printf("%i\n", (int) ftell(fp));
  }

  fclose(fp);
}

void testTokenization(char *str, char *s)  {
  char *token;
  token = strtok(str, s);

  while (token != NULL) {
    printf("Token: %s\n", token);
    token = strtok(NULL, s);
  }
}

void testVariableArgumentList(char *colors, ...)  {
  va_list ap;
  char *arg;

  va_start(ap, colors);

  while ((arg = va_arg(ap, char *)) != NULL) {
    printf("%s\n", arg);
  }

  va_end(ap);
}

void testTime() {
  /* XXX: Comparing clock_t and time_t types is pointless! */
  clock_t time = 0;
  time_t delta = 0;

  while ((time = clock()) < 100000) {
    /* delta = time - delta; */
    delta = difftime(time, delta);
    if (delta != 0) {
      printf("%i\n", delta);
    }
  }
}

void main(int argc, char *argv[]) {
  /*=====================================================================*/
  /* Diverse */
  /*=====================================================================*/

  /* printf("Test\n"); */
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

  /* printf("%s\n", getenv("EDITOR")); */

  /* XXX */
  /* bsearch(...) */
  /* qsort(...) */


  /*=====================================================================*/
  /* Iterate arrays */
  /*=====================================================================*/

  /* int someNumbers[] = { 23, 24, 25 }; */
  /* report(someNumbers); */


  /*=====================================================================*/
  /* Operations on arrays */
  /*=====================================================================*/

  /* int numbers[] = {111, 222, 333, 444, 555, 666, */
  /*                  -111, -222, -333, -444, -555, -666}; */
  /* for (int i = 0; i < nelems(numbers); ++i) { */
  /*   printf("%d: %d\n", numbers[i], invert(numbers[i])); */
  /* } */


  /*=====================================================================*/
  /* Bit shifting */
  /*=====================================================================*/

  /* printf("%d\n", 110011 >> 2); */


  /*=====================================================================*/
  /* Constants */
  /*=====================================================================*/

  /* printf("Foo: %d\n", FOO); */


  /*=====================================================================*/
  /* Pointer arguments */
  /*=====================================================================*/

  /* int x = 123; */
  /* int y = 456; */
  /* printf("Before swapping: a = %d, b = %d\n", x, y); */
  /* swapInt(&x, &y); */
  /* printf("After swapping: a = %d, b = %d\n", x, y); */


  /*=====================================================================*/
  /* Pointers to functions */
  /*=====================================================================*/

  /* int *f();    /\* f: function returning pointer to int *\/ */
  /* int (*pf)(); /\* pf: pointer to function returning int *\/ */


  /*=====================================================================*/
  /* Dispatching command line arguments */
  /*=====================================================================*/

  /* listArgv(argc, argv); */


  /*=====================================================================*/
  /* Structures */
  /*=====================================================================*/

  /* testStructures(); */


  /*=====================================================================*/
  /* Input/output test */
  /*=====================================================================*/

  /* testInput(); */

  /* printf("%.*s\n", 3, "foobarobaof"); */
  /* printf("%.2s\n", "foobarobaof"); */
  /* printf("|%8.3s|\n", "foobarobaof"); */
  /* printf("%d\n", printf("|%-8.3s|\n", "foobarobaof")); */

  /* int num; */
  /* char name[9999]; */
  /* /\* scanf("#%i, %s", &num, name); *\/ */
  /* printf("\nnum: %i\nname: %s\n", num, name); */

  /* int num; */
  /* char name[9999]; */
  /* sscanf("#123, John Doe", "#%i, %s", &num, name); */
  /* printf("\nnum: %i\nname: %s\n", num, name); */


  /*=====================================================================*/
  /* File access */
  /*=====================================================================*/

  /* testFileAccess(argv[1]); */
  /* testLineReading(argv[1]); */


  /*=====================================================================*/
  /* Character classes */
  /*=====================================================================*/
  /* testCharacterClassFunctions(); */


  /*=====================================================================*/
  /* System commands */
  /*=====================================================================*/

  /* testSystemCommand("ls -lisa"); */


  /*=====================================================================*/
  /* Mathematical functions */
  /*=====================================================================*/

  /* /\* XXX *\/ */
  /* for (int i = 0; i < 10; i++) { */
  /*   /\* printf("%d\n", sin(i)); *\/ */
  /*   /\* sin((double) i); *\/ */
  /* } */

  /* /\* XXX *\/ */
  /* double x = 3; */
  /* double y = log(x); */
  /* printf("%d\n", y); */

  /* printf("%i\n", div(43, 11)); */
  /* printf("%i\n", ldiv(43, 11)); */


  /*=====================================================================*/
  /*  */
  /*=====================================================================*/

  /* printf("RAND_MAX: %i\n", RAND_MAX); */

  /* for (int i = 0; i < 10; i++) { */
  /*   printf("%f\n", frand()); */
  /* } */


  /*=====================================================================*/
  /* Char array iteration */
  /*=====================================================================*/

  /* testArrayIteration("This is a test."); */

  /* char string[] = {'A', 'b', 'c', '.', '\0'}; */
  /* testArrayIteration(string); */


  /* FILE *fp; */
  /* fp = fopen("test.c", "r"); */
  /* printf("%i\n", fp); */

  /* printf("%s\n", _flags._READ); */


  /*=====================================================================*/
  /* Files */
  /*=====================================================================*/

  /* testFiles("testFile"); */
  /* writeCharsToFile("testFile"); */


  /*=====================================================================*/
  /* Streams */
  /*=====================================================================*/

  /* testStreams("test.h"); */


  /*=====================================================================*/
  /* ASCII characters */
  /*=====================================================================*/

  /* printf("%c\n", (char) 0x7E); */


  /*=====================================================================*/
  /* Strings */
  /*=====================================================================*/

  /* char s1[] = "abc"; */
  /* char s2[] = "klm"; */
  /* printf("%i\n", strcmp(s1, s2)); */

  /* printf("%s\n", strchr("This is a string.", 'i')); */
  /* printf("%s\n", strrchr("This is a string.", 'i')); */
  /* printf("%s\n", (strchr("This is a string.", 'X') == NULL) ? */
  /*     "Yes." : "No."); */

  /* char str[] = "This is a string."; */
  /* char s[] = "i"; */
  /* testTokenization(str, s); */


  /*=====================================================================*/
  /* Program termination */
  /*=====================================================================*/

  /* atexit(*say); */


  /*=====================================================================*/
  /* assert.h */
  /*=====================================================================*/

  /* assert(1 == 1); */
  /* assert(1 == 3); */


  /*=====================================================================*/
  /* Variable argument lists */
  /*=====================================================================*/

  /* XXX */
  /* testVariableArgumentList("red", "green", "blue", "yellow"); */


  /*=====================================================================*/
  /* Time */
  /*=====================================================================*/

  /* for (int i = 0; i < 24000; i++) { */
  /*   printf("%s\n", "---"); */
  /* } */

  /* testTime(); */

  /* for (int i = 0; i < 10000; i++) { */
  /*   printf("%i\n", time(NULL)); */
  /* } */

  /* struct tm t; */
  /* t.tm_sec    = 10; */
  /* t.tm_min    = 10; */
  /* t.tm_hour   = 6; */
  /* t.tm_mday   = 25; */
  /* t.tm_mon    = 2; */
  /* t.tm_year   = 89; */
  /* t.tm_wday   = 6; */
  /* printf("%s", asctime(&t));  /\* Newline already in timestring *\/ */


  /*=====================================================================*/
  /* Limits */
  /*=====================================================================*/

  /* printf("CHAR_BIT: %i\n", CHAR_BIT); */
  /* printf("CHAR_MAX: %i\n", CHAR_MAX); */
  /* printf("CHAR_MIN: %i\n", CHAR_MIN); */
  /* printf("INT_MAX: %i\n", INT_MAX); */
  /* printf("INT_MIN: %i\n", INT_MIN); */
  /* printf("LONG_MAX: %i\n", LONG_MAX); */
  /* printf("LONG_MIN: %i\n", LONG_MIN); */
  /* printf("SCHAR_MAX: %i\n", SCHAR_MAX); */
  /* printf("SCHAR_MIN: %i\n", SCHAR_MIN); */
  /* printf("SHRT_MAX: %i\n", SHRT_MAX); */
  /* printf("SHRT_MIN: %i\n", SHRT_MIN); */
  /* printf("UCHAR_MAX: %i\n", UCHAR_MAX); */
  /* printf("UINT_MAX: %i\n", UINT_MAX); */
  /* printf("ULONG_MAX: %i\n", ULONG_MAX); */
  /* printf("USHRT_MAX: %i\n", USHRT_MAX); */


  /*=====================================================================*/
  /* Determine the page size */
  /*=====================================================================*/

  printf("Page size on this system: %ld bytes\n", sysconf(_SC_PAGESIZE));


  /*=====================================================================*/
  /*  */
  /*=====================================================================*/
}
