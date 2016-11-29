#include <stdio.h>
#include <stdlib.h>

typedef char String[128];

double* input_matrix(int *row, int *col, char * name){
  //get the number of rows from user
  printf("Enter number of rows: ");
  scanf("%d", row);
  //get the number of columns from user
  printf("Enter number of cols: ");
  scanf("%d", col);
 
  //create double pointer which will be returned by function
  double* m;
  m = (double *)(malloc((sizeof(double) * (*row * *col))));
  int i = 0;
  //this is the outer loop - going thru rows
  while (i < *row) {
    int j = 0;
    //this is the nested loop - going thru columns
    while (j < *col) {
      printf("Enter element [%d, %d]: ", i+1, j+1);
      scanf("%lf", m + j +(i * (*col)));
      j++;
    } //end nested loop
    i++;
  } //end outer loop
  printf("End of  %s\n", name);
  return m;
}

void output_matrix(double *matrix, int row, int col) {

  int i = 0;
  //start outer loop to go thru rows
  while (i < row) {
    int j = 0;
    //start inner loop to go trhru cols
    while (j < col) {
      printf("%f ", *(matrix + j + (i * col)));
      j++;
    } //end nested loop
    //print newline
    printf("\n");
    i++;
  } //end outer loop 


}

int matrix_multiply(double* m1, int row1, int col1, double* m2, int row2, int col2, double* m3) {
  if (col1 != row2) {
    puts("ERROR! columns and rows don't match");
     return -1;
  }
  //start outer loop
  int i = 0;
  while (i < row1) {
    int j = 0;
    //start inner loop
    while (j< col2) {
      double sum = 0;
      int k = 0;
      while (k < col1) {
        int x;
        x = *(m1 + k + (i*col1));
        int y;
	y = *(m2 + j + (k*col2));
        sum += (x*y);
        k++;
      }
      *(m3 + j + (i*col2)) = sum;
      j++;
    } //end inner loop
    i++;
  } //end outer loop
  return 1; //this is for the boolean condition
}


//main method, given by professor

int main(void) {

  double *m1,*m2,*m3;
  int m1_rows,m1_columns,m2_rows,m2_columns;

  if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
      ((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
      ((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
    printf("Matrix 1\n");
    output_matrix(m1,m1_rows,m1_columns);
    printf("Matrix 2\n");
    output_matrix(m2,m2_rows,m2_columns);
    if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
      printf("Product\n");
      output_matrix(m3,m1_rows,m2_columns);
      free(m1);
      free(m2);
      free(m3);
      return(0);
    } else {
      printf("Error in dimensions\n");
      free(m1);
      free(m2);
      free(m3);
      return(-1);
    }
  } else {
    free(m1);
    free(m2);
    free(m3);
    printf("Error allocating memory\n");
    return(-2);
  }
}
