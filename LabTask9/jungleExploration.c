#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------

#define MAXSTRLEN 128 

//--------------------------------------------------------- 

typedef char String[MAXSTRLEN];

//create enum
typedef enum {
  mammal,
  insect,
  bird,
  fish,
  null
} AnimalType;

//create the struct
typedef struct {
  String name;
  double size;
  AnimalType type;
} Record;

//this function will return an AnimalType value
AnimalType inputAnimalType(String type) {
  if(!strcmp(type, "mammal")) {
    return mammal;
  }
 else if(!strcmp(type, "insect")) {
    return insect;
  }
 else if(!strcmp(type, "bird")) {
    return bird;
  }
 else if(!strcmp(type, "fish")) {
    return fish;
  }
 else {
    printf("Invalid type");
    exit(1);
  }
}


//this function returns a string from an AnimalType input
char * stringAnimalType(AnimalType type) {
  switch(type) {
  case mammal: return "mammal";
  case insect: return "insect";
  case bird: return "bird";
  case fish: return "fish";
  default: return "ERROR!!! invalid type! exiting\n";
  }
}

//this function prints out the records
void print(Record * log, int logSize) {
  printf("\nThe following new species were found:\n");
  int i;
  for(i = 0; i < logSize; i++) {
    Record animal = log[i];
    printf("%-20s has size %6.2lf and is a %s\n",animal.name, animal.size, stringAnimalType(animal.type));
  }
  free(log);
}

//--------------------------------------------------------- 

int main(void) {
  //create a section of memory for the first entry
  Record * rec = (Record *)malloc(1 * sizeof(Record)); //1 is the initial value
  int recSize = 1;
  int index = -1;

  while(1) {
    index++;
    //double the size of the memory if it is full
    if(index == recSize) {
      recSize *= 2; //this is the reallocation size
      rec = (Record *)realloc(rec, recSize * sizeof(Record));
      if(rec == NULL) {
	printf("Error allocating memory");
	exit(1);
      }
    }
    Record record;
    String type;
    //get the animal information and store in record
    printf("Enter animal information (\"exit\" to exit)\n");
    printf("What is the name : ");
    scanf("%s", record.name);
    if(!strcmp(record.name,"exit")) {
      break;
    }
    printf("What is the size : ");
    scanf("%lf", &record.size);
    printf("What is the type : ");
    scanf("%s", type);
    record.type = inputAnimalType(type);
    //add record to animal log
    rec[index] = record;
  }
  //print the animal log
  print(rec, index);
  return 0;
}
