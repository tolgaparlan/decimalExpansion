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

int biggestPrimeDivisor(int num){//biggest prime divisor which is not 2 or 5
	int div =1 ;//iterator for the divisor check
	
	while(isDivbyFive(num)){//divides until can no more be divided
		num /= 5;
	}
	while(isDivbyTwo(num)){//divides until can no more be divided
		num /= 2;
	}
	
	for(int i=1;i*i<=num;i+=2){//don't need to be extremely efficient. can improve if you want
		if(isPrime(i) && num%i==0){
			div=i;
		}
	}
	return ((num/div)>div && isPrime(num/div) ? (num/div) : div); //return the biggest. For numbers like 77, because the iterator doesnt reach 11.
}

void simplify(int *fraction){	//fraction is a 2 cell array of numerator and denominator
	for(int i=2;i<=fraction[1];i++){ //fraction[1] is the denominator. assume that den is always bigger
		while(fraction[0]%i==0 && fraction[1]%i==0){
			fraction[0] /= i;
			fraction[1] /= i;
		}
	}
}

int findRepetition(char *decimal, int charLen, int lenRep){//takes the decimal point string and length of repetition as input. returns the index the repetition starts
	int match;//stores number of same chars
	for(int i=1;i<charLen;i++){ //0th char is not repetitive anyway
		match=0;
		for(int j=0;j<lenRep;j++){//check the series for each digit
			if(decimal[i+j]==decimal[i+j+lenRep]){ //check if repeats
				match++;
			}
		}
		if(match==lenRep){//if all the repeating digits were present.
			return i;
		}
	}
	return -1; //if everything goes well, the function should never reach here	
}


int main(int argc, char **argv)
{
	
	return 0;
}

