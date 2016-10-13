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

int divByTwoFive(int num){ //checks if a number is divisable 2 and 5
	return(isDivbyFive(num)&&isDivbyTwo(num) ? 1 : 0);
}

//Check for 10^k = 1(mod n), k=length of repetation, n=biggest prime divisor of den
int lengthOfRepetition(int n){ //N SHOULDNT BE 2 OR 5!!
	int k;
	long tenPower = 10; //just in case this number gets too big, made it a long
	for(k=1;tenPower%n != 1;k++){
		tenPower *= 10;
	}
	return k;	
}

int checkTwoFive(int num){//checks if the number is in 2^a * 5^b form
	while(isDivbyFive(num)){//divides until can no more be divided
		num /= 5;
	}
	while(isDivbyTwo(num)){//divides until can no more be divided
		num /= 2;
	}
	return (num==1 ? 1: 0); //1 if valid, 0 if not
}

int main(int argc, char **argv)
{
	return 0;
}

