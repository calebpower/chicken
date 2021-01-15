#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if(argc != 3) {
    printf("Bad args.\n");
    return 1;
  }

  FILE *inputFile;
  inputFile = fopen(argv[1], "r");
  if(inputFile == NULL) {
    printf("Bad input file.\n");
    return 2;
  }

  FILE *outputFile;
  outputFile = fopen(argv[2], "w");

  char chicken[] = "chicken";

  char count = '\0';
  int line = 1;
  int col = 1;
  int idx = 0;
  char ch;

  while((ch = fgetc(inputFile)) != EOF) {
    printf("%c", ch);

    if(col == 1 && ch == '\n') { // first column, if it's a newline
      printf("--- blank\n"); // then the line is blank
      line++; // so increase the line count, but keep col and count the same
    } else if(idx == 6 && ch == chicken[6]) { // if we're on the 'n' of 'chicken'
      count++; // that's one more chicken
      col++; // increase the col
      idx = 0; // but reset the mod idx
    } else { // for every other case
      if(ch == ' ' && idx == 0) { // if we run into a space and we aren't in the middle of a chicken
        col++; // treate that as a valid token and up the line
      } else if(ch == '\n' && idx == 0) { // if we run into a newline and we aren't in the middle of a chicken
        printf("--- %d\n", (int)count); // make sure to make known the number of chickens in the line
        idx = 0; // and reset the mod index for the next line
        fputc((int)count, outputFile);
        count = '\0'; // and reset the count for the next line
        line++; // and up the line
        col = 1; // and reset the column count
      } else if(idx < 7 && chicken[idx] == ch) { // the only remaining case is if we're in the middle of a chicken
        col++; // in which case, up the column number
        idx++; // and the index number
      } else { // if all else fails, it's a bad chicken
        printf("\nMalformed chicken at line %d, col %d with idx %d and count %d\n", line, col, idx, (int)count); // so let it be known
        return 3; // and exit accordingly
      }
    }
  }


  fclose(inputFile);

  return 0;
}
