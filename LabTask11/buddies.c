#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define EXIT_SUCCESS 0

typedef char String[80];

typedef struct LinkedNodeTag {
  String name;
  struct LinkedNodeTag *bestAlly;
  struct LinkedNodeTag *nextNode;
} LinkedNode;

typedef LinkedNode *LinkedNodePointer;

//--------------- MAIN ----------------------------

int main(void) {

  LinkedNodePointer head = NULL;
  LinkedNodePointer newNode;
  String keyInput;

  //get the list of names
  printf("Enter person name : ");
  //get and process next line
  while(fgets(keyInput, 80, stdin) != NULL) {
    if (keyInput[strlen(keyInput) - 1] != '\n') {
      char c;
      while((c = getchar()) != '\n' && c != EOF) {}
      perror("Input too long! Truncating");
    }
    //this takes care of the newline
    keyInput[strlen(keyInput) - 1] = '\0';   
    //check if its empty string
    if(!strcmp(keyInput, "")) {               
      break;
    }
    //malloc some memory for new node
    newNode = (LinkedNodePointer)malloc(sizeof(LinkedNode));
    //add new node to list
    strcpy(newNode->name, keyInput);
    newNode->nextNode = head;
    head = newNode;
    //prompt for more input
    printf("Enter person name : ");
  }

  //assign best friends
  LinkedNodePointer tempNode = head;
  //loop through enitre list
  while(tempNode != NULL) {
    //get best ally
    printf("Enter best ally name for %s : ",tempNode->name);
    scanf("%s", keyInput);
    //find that node
    LinkedNodePointer inner = head;
    while(inner != NULL) {
      if(!strcmp(inner->name,keyInput)) {
        // set best friend
	tempNode->bestAlly = inner;
	break;
      }
      inner = inner->nextNode; 
    }
    //best friend not in list
    if(tempNode->bestAlly == NULL) {
      puts("Not a valid friend");
    } else {
      tempNode = tempNode->nextNode; 
    }
  }

  //print the list
  for(tempNode = head; tempNode != NULL; tempNode = tempNode->nextNode){
    printf("The best ally of %s is %s\n", tempNode->name, \
	   tempNode->bestAlly->name);
  }

  while (head != NULL) {
    newNode = head;
    head = head->nextNode;
    //IMPORTANT freeing the node !!!!!!!!!
    free(newNode);
  }
  return(0);
}
