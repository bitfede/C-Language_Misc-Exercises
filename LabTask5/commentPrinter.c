#include <stdio.h>
#include <stdlib.h>

void printIt(char letter) {
  printf("%c", letter);
}

void clearLine() {
  printf("\n");
}

int main() {
  //variables
  char input;
  int mode = 0;

puts("type your C code here: ");
  
  while ((input = getchar()) != EOF) {
    
    if (mode == 4) {
      if (input == '/') {
        mode = 0;
        clearLine();
      }
      else {
        mode = 3;
      }
    }

    if (mode == 0 && input == '/') {
      mode = 1;
      //puts("firstslash"); //debug
      continue;
    }

    if (mode == 1) {
      switch (input) {
      case '/':
	mode = 2;
        //puts("second slash"); //debug
	continue;
        break;

      case '*':
        mode = 3;
        continue;
	break;

      default:
	mode = 0;
      }	

    }

    if (mode == 3 || mode == 2) {
      if (mode == 2 && input == '\n') {
        //puts("triggerSTOP here"); //debug
        mode = 0;
        clearLine();
      }
      else if (mode == 3 && input == '*') {
        mode = 4;
      }
      else {
	printIt(input);
      }
      
    } 

  }//while

}
