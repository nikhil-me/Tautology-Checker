/* 
 * Date : 14 August 2010
 * Name of program : tautology-check.c
 * Program to check if the given logical expression is a tautology
 * Idea - To use the general truth-table program and
 * see if the output is always 1 or always 0
 * Successful!
 * Works with command line arguments
 */

#include <stdio.h>
#include <string.h>

char ipstr[100] = "";
int fnvalues[1000], numvar;

int get_expression(char ipstr[])
{
     printf("Operators : \n& AND\n! Not\n| OR\n");
     printf("Use any alphabets to denote your variables\n");
     printf("Please enter your logical expression : \n");
     
     gets(ipstr);
}

int test_for_tautology(int arr[], int numvar)
{
     int i, flag = 0;
     for(i=0; i<(1<<numvar); i++){
	  if(!arr[i]){
	       flag = 1;
	  }
     }
     if(!flag)
	  return 1;		/* Tautology */
     
     flag = 0;
     for(i=0; i<(1<<numvar); i++){
	  if(arr[i]){
	       flag = 1;
	  }
     }
     if(!flag)
	  return 2;		/* Contradiction */

     return 0;			/* General function */
}

int main(int argc, char *argv[])
{
     int test;
     if(argc == 1){
	  get_expression(ipstr);
	  if(truth_table(ipstr, fnvalues, &numvar))
	       return 1;
	  test = test_for_tautology(fnvalues, numvar);
	  if(test == 1)
	       printf("\nYAY!! Given expression is a Tautology!!\n");
	  else if (test == 2)
	       printf("\nThe given expression is a Contradiction!\n");
	  else
	       printf("\nThe given expression is neither a Tautology nor"
		      " a Contradiction!\n");
     }
     else if(argc != 2){
	  printf("Please enter exactly one logical expressions!");
	  return 0;
     }
     else{
	  strcpy(ipstr, argv[1]);
	  if(truth_table(ipstr, fnvalues, &numvar))
	       return 1;
	  test = test_for_tautology(fnvalues, numvar);
	  if(test == 1)
	       printf("\nYAY!! Given expression is a Tautology!!\n");
	  else if (test == 2)
	       printf("\nThe given expression is a Contradiction!\n");
	  else
	       printf("\nThe given expression is neither a Tautology nor "
		      "a Contradiction!\n");
     }
     return 0;
}
