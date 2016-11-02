#include <stdio.h>
#include <stdlib.h>

int main() {
  
  float     sideSquare;
  float     roadLength;
  int       kangarooCount;
  float     kangarooDensity;
  float     roadSurface;
  float     finalResult;

  //obtaining info from stdin
  printf("Enter side of square in km: ");
  scanf("%f", &sideSquare);
  printf("Enter the length of roads: ");
  scanf("%f", &roadLength);
  printf("Enter the number of Kangaroos: ");
  scanf("%i", &kangarooCount);
  //printf("%f\t%f\t%i\n", sideSquare, roadLength, kangarooCount); // debug input info
  
  //calculate kangaroo density
  kangarooDensity = sideSquare / kangarooCount;
  //calculate road surface area
  roadSurface = roadLength * (0.1); //road length is in km, so I am coverting 10 meters in km by divinding them by 1000
  
  //'sup Kyle

  // calculate totalall
  finalResult = (kangarooDensity + roadSurface) * 1.47;
  
  //output total to user
  printf("Expected number of kills is : %.2f\n", finalResult);
  //printf("result-> %f\n", finalResult); //Debug result check
  
  //putting 0 into %eax and sending exit interrupt to kernel .. so if we do $echo $? after we get zero as output ;) ;) ;)
  return(EXIT_SUCCESS);

}
