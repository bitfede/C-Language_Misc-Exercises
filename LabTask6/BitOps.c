#include <stdio.h>
#include <stdlib.h>

#define ODD(X) ((X) & 01)
#define BITON(X,N) (ODD((X) >> (N)))
//we need a mask with start and finish bits equal to 1
#define MASK(M) ((1 << (M)) - 1)
//we use the mask to compare it with the given number in binary
#define ALLON(X,S,E) ((((X) >> (S)) & MASK((E)-(S)+1)) == MASK((E)-(S)+1))
//we compare it with the == operator, if both values on both sides are equal
//it means that the number has all the bits on in the range, because we AND
//together the mask with the binary number (1 & 1 = 1) , (1 & 0 = 0), (0 & 1 = 0)
//-----------------------------------------------------------------------------
int main(void) {

    unsigned int U1,BitNumber,Start,End;

    printf("Enter an integer : ");
    scanf("%ud",&U1);
    printf("%u is %s\n",U1,ODD(U1)?"odd":"even");
    
    //return(0); //FIRST DEBUG
    printf("Enter an integer and a bit number : ");
    scanf("%u %d",&U1,&BitNumber);
    printf("%u has bit %d %s\n",U1,BitNumber,BITON(U1,BitNumber)?"on":"off");
    
    //return(0); //SECOND DEBUG
    printf("Enter an integer, start and end bit numbers : ");
    scanf("%u %u %u",&U1,&Start,&End);
    printf("%u has %s those bits on\n",U1,ALLON(U1,Start,End)?"all":"not all");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
