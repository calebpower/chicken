#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if(argc != 2) {
    printf("Bad args.\n");
    return 1;
  }

  FILE *file;
  file = fopen(argv[1], "r");
  if(file == NULL) {
    printf("Bad file.\n");
    return 2;
  }

  char ch;
  while((ch = fgetc(file)) != EOF)
    printf("%c", ch);

  fclose(file);

  return 0;
}
