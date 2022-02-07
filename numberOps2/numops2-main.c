#include <stdio.h>
#include "numops2-header.h"


int sumall(int a[], int size);
int is_prime(int num);
int even_odd(int num);
int reverse_number(int num);
int main(void) 
{ 
	char ch = 'N'; /* variable to accept the user's choice, 
										N represents the condition not to exit from the program */ 
	int num; 
	int a[]={0,1,2,3,4};
	int base;
	int exponent;
	/* variable to accept a number */ 
	while( ch != 'Y' &&  ch != 'y')
	{ 

		printf("Enter R to reverse the digits of the number \n"); 
		printf("Enter E to determine if the number is even or odd \n"); 
		printf("Enter P to determine if the number is prime \n");  
		printf("Enter S or to sum all input numbers \n");
		printf("Enter B or to calculate power function \n");
		printf("Enter Y or y to exit the program\n");
		printf("Enter your choice: "); 

		scanf("%c", &ch); 
		while(getchar() != '\n'); /*clears the input buffer */ 

		switch(ch) 
		{
			case 'R': case 'r': 
			    printf("Enter the number to be reversed:\n"); 
			    scanf("%d", &num);
			    while(getchar() != '\n');
			    int reversed=reverse_number(num);
			    printf("Reversed value of your input is %d\n\n", reversed);
			    break;

			case 'E': case 'e': 
			    printf("Enter the number to check if it is even or odd:\n"); 
			    scanf("%d", &num); 
			    while(getchar() != '\n');
			    {
			        int even=even_odd(num);
			        if(even==1)
			    	printf("Your number is even \n\n");
			        else
			    	printf("Your number is odd \n\n");
			    }
			    break; 

			case 'P': case 'p': 
			    printf("Enter the number to check if it is prime or not:\n"); 
			    scanf("%d", &num); 
			    while(getchar() != '\n'); 
			    if(is_prime(num)==1)
			    {
			        printf("Your number is prime. \n\n");
			    }
			     else 
			    {
			        printf("Your number is not prime \n\n");
			    }
			    break; 
			
			case 'S': case 's':
			    printf("Array sum: %d\n\n", sumall(a,3));
			    break;

			case 'B': case 'b':
			    printf("Enter the base and exponent you'd like to calculate: \n");
			    scanf("%d %d", &base, &exponent);
			    printf("Your calculation is: %d to the power of %d =  %d\n\n", base, exponent, power(base,exponent));
			    break;

			case 'Y': case 'y': 
			    printf("Exiting the program.\n\n"); 
			    break;

			default: 
			    printf("You have entered a wrong choice. Try again\n"); 
			    break; 
		} /* switch */
	} /* while */ 
	return 0; 
} /* main */ 
