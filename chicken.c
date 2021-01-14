#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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

  struct Stack *p = newStack(5);

  push(p, 1);
  push(p, 2);
  push(p, 3);

  printf("Top element is %d\n", peek(p));
  printf("Stack size is %d\n", size(p));

  pop(p);
  pop(p);
  pop(p);

  if (isEmpty(p))
    printf("Stack is empty");
  else
    printf("Stack is not empty");

  return 0;
}
