/********************************************************************** 
 * Program : To get an expression as argument and construct truth table
 * Successful!!!
 * Things to learn :
 *** Approach the problem from a high-level
 *** Abstract away all the different procedures for easier testing and bug removal
 * Works with command line arguments!!
 * NOTE : Passing a string will allow the function to change it!!!
 * BE CAREFUL!!
************************************************************************/



#include <stdio.h>
#include <string.h>


char opstr[100]="";		/* Postfix expression */
char listvar[100];		/* List of variable names (char) */
int numvar, valvar[100];
int precedence[256];		/* Precedence for tokens and variables */

int truth_table(char ipstr[], int fnvalues[], int *no_of_variables){
     int i, j, output, len;
	  
     remove_spaces(ipstr);
     
     if(check_for_valid_characters(ipstr)){
	  printf("ERROR! Use only valid characters - ~&|() a-z A-Z\n");
	  return 1;
     }

     set_precedence(precedence,  ipstr);
     get_variables(listvar, &numvar, precedence);

     if(conv_to_postfix(ipstr, opstr, precedence) == 1){
	  printf("\nError in input\n");
	  return 1;
     }

     len = strlen(ipstr);
     /* Truth-table Printing */
     printf("\n");
     for(i=0; i<numvar; i++){
	  printf("%c  ", listvar[i]);
     }
     printf("%s ", ipstr);
     
     for(i=0; i<(1<<numvar); i++){
	  /* For each permutation of bits */
	  printf("\n");
	  compute_val_var_from_perm(i, valvar, numvar);
	  for(j=0; j<numvar; j++)
	       printf("%d  ", valvar[j]);
	  output = eval_postfix(opstr, valvar, numvar, listvar);
	  if(output == 1){
	       printf("Error : eval - not enuff operands\n");
	       return 1;
	  }
	  fnvalues[i] = output - '0';
	  printf("%*c ", len/2 + 1, output);
     }

     *no_of_variables = numvar;
     printf("\n");
     return 0;
}
