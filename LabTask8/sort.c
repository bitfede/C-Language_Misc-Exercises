#include <stdio.h>
#include <stdlib.h>

//-----------------------------
#define ARRLEN 5
//------------------------------

void bubblePtrSort(int * arr[])
{
  int c, d;
  int* t;

  for (c = 0 ; c < ( ARRLEN - 1 ); c++)
    {
      for (d = 0 ; d < ARRLEN - c - 1; d++)
        {
          if (arr[d] < arr[d+1])
            {
              //swaps
              t         = arr[d];
              arr[d]   = arr[d+1];
              arr[d+1] = t;
            }
        }
    }
}

void bubbleSort(int arr[])
{
  int c, d, t;
 
  for (c = 0 ; c < ( ARRLEN - 1 ); c++)
    {
      for (d = 0 ; d < ARRLEN - c - 1; d++)
	{
	  if (arr[d] > arr[d+1])
	    {
	      //swaps
	      t         = arr[d];
	      arr[d]   = arr[d+1];
	      arr[d+1] = t;
	    }
	}
    }
}

void printArray(int arr[]) {
  int i;
  for (i = 0; i < ARRLEN; i++) {
    printf("%i : %i\n", i , arr[i]);
  }

}

void printPtrArr(int* arr[]) {
  //prints the integers pointed to by an array of five pointers to integers
  int i;
  for (i = 0; i < ARRLEN; i++) {
    printf("p%i : %i\n", i, *arr[i]); 
  }
}

void initialize(int intArr[], int* intPtrArr[]) {
  int i = 0;
  for (i = 0; i < ARRLEN; i++ ) { 
     int pidNum = getpid() + i;
     srand(pidNum);
     intArr[i] = rand();
     // printf( "ints:     %i\n", intArr[i]  ); //debug
     intPtrArr[i] = &intArr[i];
     // printf( "intPtrs:  %i\n", intPtrArr[i]); //debug
  }  
  //printArray(intArr); //debug
  //puts("---"); //debug
  //printPtrArr(intPtrArr); //debug
}

int main() {
  
  int*     intPtr;
  int      intArr[5];
  int*     intPtrArr[5];

  initialize(intArr, intPtrArr);
  
  puts("---- initialized array of integers ----");
  printArray(intArr);
  bubbleSort(intArr);
  puts("--- Sorted array of pointers ----");
  bubblePtrSort(intPtrArr);
  printArray(intArr);
  puts("---- Sorted array of integers ----");
  bubbleSort(intArr);
  printArray(intArr);
  puts("---- Array of pointers ----");
  printPtrArr(intPtrArr);
  return(0);
}
