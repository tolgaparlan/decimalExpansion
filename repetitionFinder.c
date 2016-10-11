/* Finds repetitions and shit.
 * 
 * 
 */

#include <stdio.h>

int isPrime(int num){ //checks if a number is prime or not
	if(num==2 || num==3 || num==5){ //basic cases
		return 1;
	}
	if (num%2==0 || num%3==0 || num==1 ||num%5==0){ //basic cases
		return 0;
	}
	for(int i=6;i*i<num;i+=6){ 
		if(num%(i+1)==0 || num%(i-1)==0){ //every prime number is in the form of 6k+-1
			return 0; //not prime
		}		
	}
	return 1; //prime
}

int isDivbyTwo(int num){ //checks if a number is divisable by 2
	return (num%2==0 && num>0 ? 1 : 0);
}

int isDivbyFive(int num){ //checks if a number is divisable 5
	return (num%5==0 && num>0 ?  1 :0);
}

int divByTwoFive(int num){ //checks if a number is divisable 5
	return(isDivbyFive(num)&&isDivbyTwo(num) ? 1 : 0);
}

int main(int argc, char **argv)
{
	return 0;
}

