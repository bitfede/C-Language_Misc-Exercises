#include <stdio.h>
#include <stdlib.h>

const float RICHRATE = 0.25;
const float MEDIUMRATE = 0.10;
const float POORRATE = 0.03;

float inputIncDed() {
  float input;

  printf("Enter next amount: ");
  scanf("%f", &input);
  //printf("DEBUG\tinput  = %f\n ",input); //debug
  return input;
}

float ComputeTaxableIncome(float income, float deductions) {
  float taxableIncome;
 if (income >= deductions) {
    taxableIncome = income - deductions;
  }
 else {
    taxableIncome = 0.0;
 }
 return taxableIncome;
}

char ComputeTaxGroup(float taxable) {
  if (taxable >= 500000) {
    return 'S';
  }
  else if (taxable >= 200000) {
    return 'Q';
  }
  else if (taxable >= 100000) {
    return 'M';
  }
  else if (taxable >= 50000) {
    return 'A';
  }
  else if (taxable >= 20000) {
    return 'R';
  }
  else {
    return 'P';
  }
}

float ComputeTax(float taxableIncome, char taxGroup) {
  float tax;
  if (taxGroup == 'S' || taxGroup == 'Q') {
    tax = taxableIncome * RICHRATE;
  }
  else if (taxGroup == 'M') {
    tax = taxableIncome * MEDIUMRATE;
  }
  else if (taxGroup == 'A' || taxGroup == 'R') {
    tax = taxableIncome * POORRATE;
  }
  else if (taxGroup == 'P') {
    tax = 0.0;
  }
  else {
    printf("ERROR");
    return;
  }
  if (tax > 50000) {
    tax = 50000;
  }
  return tax;
}

void DisplayData(float income, float deductions, float taxableIncome, char taxGroup, float taxTotal) {
  printf("Income\t\t\t= $%.2f\n", income);
  printf("Deductions\t\t= $%.2f\n", deductions);
  printf("Taxable Income\t\t= $%.2f\n", taxableIncome);
  printf("Tax group\t\t= %c\n", taxGroup);
  printf("Tax owed\t\t= $%.2f\n", taxTotal);
}

int main() {
  float    input;
  float    income = 0;
  float    deductions = 0;
  float    taxableIncome;
  char     taxGroup;
  float    taxes;

  do {
    input = inputIncDed();
    if (input >= 0) {
      income = income + input;
    }
    else {
      deductions = deductions + abs(input);
    }
  } while(input != 0);

  //printf("DEBUG\tinput  = %f\n",input); //debug
  //printf("DEBUG\tincome = %f\n", income); //debug
  //printf("DEBUG\tdeductions = %f\n", deductions); //debug
  
  taxableIncome = ComputeTaxableIncome(income, deductions);
  //printf("DEBUG\t taxableIncome = %f\n", taxableIncome);
  
  taxGroup = ComputeTaxGroup(taxableIncome);
  //printf("DEBUG\t taxGroup = %c\n", taxGroup);

  taxes = ComputeTax(taxableIncome, taxGroup);
  //printf("DEBUG\t taxes = %f\n", taxes);
  
  DisplayData(income, deductions, taxableIncome, taxGroup, taxes);

  return(EXIT_SUCCESS);
}
