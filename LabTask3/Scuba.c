#include <stdio.h>
#include <stdlib.h>

float determineAmbientPress(float diveDepth) {

  float ambPress = ( diveDepth/33.0 ) + 1;

  return ambPress;
}

float determineO2PartPress(int percOxi, float ambPress) {

  float oxiPartP = ( percOxi / 100.0 ) * ambPress;

  return oxiPartP;
}


char determineOxiPart(float oxiPartP) {
  char oxiGroup;

if ( (oxiPartP >= 0.0) && (oxiPartP < 0.1)) {
    oxiGroup = 'A';
  }
  else if ((oxiPartP >= 0.1)&&(oxiPartP < 0.2)) {
    oxiGroup = 'B';
  }
  else if ((oxiPartP >= 0.2)&&(oxiPartP < 0.3)) {
    oxiGroup = 'C';
  }
  else if ((oxiPartP >= 0.3)&&(oxiPartP < 0.4)) {
    oxiGroup = 'D';
  }
  else if ((oxiPartP >= 0.4)&&(oxiPartP < 0.5)) {
    oxiGroup = 'E';
  }
  else if ((oxiPartP >= 0.5)&&(oxiPartP < 0.6)) {
    oxiGroup = 'F';
  }
  else if ((oxiPartP >= 0.7)&&(oxiPartP < 0.8)) {
    oxiGroup = 'G';
  }
  else if ((oxiPartP >= 0.8)&&(oxiPartP < 0.9)) {
    oxiGroup = 'H';
  }
  else if ((oxiPartP >= 0.9)&&(oxiPartP < 1.0)) {
    oxiGroup = 'I';
  }
  else if ((oxiPartP >= 1.0)&&(oxiPartP < 1.1)) {
    oxiGroup = 'J';
  }
  else if ((oxiPartP >= 1.1)&&(oxiPartP < 1.2)) {
    oxiGroup = 'K';
  }
  else if ((oxiPartP >= 1.2)&&(oxiPartP < 1.3)) {
    oxiGroup = 'L';
  }
  else if ((oxiPartP >= 1.3)&&(oxiPartP < 1.4)) {
    oxiGroup = 'M';
  }
  else if ((oxiPartP >= 1.4)&&(oxiPartP < 1.5)) {
    oxiGroup = 'O';
  }
  else {
    oxiGroup = 'P';
  }

 return oxiGroup;
}


int main() {
  
  //variables
  int    diveDepth;
  int    percOxi;
  float  ambPress;
  float  oxiPartP;
  char   oxiGroup;
  //get info from users
  printf("Enter depth and percentage O2: ");
  scanf("%i%i", &diveDepth, &percOxi);
  
  ambPress = determineAmbientPress(diveDepth);
  oxiPartP = determineO2PartPress(percOxi,ambPress);

  oxiGroup = determineOxiPart(oxiPartP);

  //printf("divedepth: %i\tpercoxi: %i\t\n", diveDepth, percOxi); // debug test input correct
  printf("Ambient Pressure: %f\nO2 Pressure: %f\nO2 Group: %c\n", ambPress, oxiPartP, oxiGroup);
  printf("Exceeds Maximal Pressure: ");
  if (oxiGroup == 'O') {
    printf("true\n");
  }
  else {
    printf("false\n");
  }
  printf("Exceeds Contingency Pressure: ");
  if (oxiGroup == 'P') {
    printf("true\n");
  }
  else {
    printf("false\n");  
}


  return(EXIT_SUCCESS);

}
