// Include Files
#include <stdio.h>
// Project Includes
#include "number-header.h"
// Function Implementations

int reverse_number(int num)
{ 
	int reversed =0;
	while(num>0)
	{
	    reversed=reversed*10 + num%10;
	    num=num/10;
	}
	return reversed;
}

int even_odd(int num)
{
	int even = 0;
	    if(num%2 ==0) {
		even=1; }
	return even;
}


int is_prime(int num)
{
	int i, flag = 1;
	for (i=2; i<= num/2;++i)
		if(num%i ==0) {
			flag=0;}
	return flag;
		
}

