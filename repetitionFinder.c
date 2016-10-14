/* Finds repetitions and shit.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

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

//Check for 10^k = 1(mod n), k=length of repetation, n=biggest prime divisor of den
int lengthOfRepetition(int n){ //N SHOULDNT BE 2 OR 5!!
	n = biggestPrimeDivisor(n);
	int k;
	long tenPower = 10; //just in case this number gets too big, made it a long
	for(k=1;tenPower%n != 1;k++){
		tenPower *= 10;
	}
	return k;	
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
	for(int i=0;i<charLen;i++){ //because of the dot character, non-decimal points will never be mistaken
		match=0;
		for(int j=0;j<lenRep;j++){//check the series for each digit
			if(decimal[i+j]==decimal[i+j+lenRep]){ //check if repeats
				match++;
			}
		}
		if(match==lenRep){//if all the repeating digits were present.
			return i; //return the index repetition starts
		}
	}
	return -1; //if everything goes well, the function should never reach here	
}

int isAllNines(int num){//helper function for expandToNine
	while(num){ 
		if(num%10!=9){
			return 0; //not
		}
		num /=10;
	}	
	return 1; //yep
}

void expandToNine(int *fraction){ //expand den and num until den is in a form of all 9
	int den=fraction[1], num=fraction[0];	
	for(int i=1;!isAllNines(fraction[1]);i++){ //it's not extremely efficient but does the job. can be immproved	
		fraction[0] = num*i;
		fraction[1] = den*i;
	}
}

int numBigger(int *fraction){//if the num is bigger than num
	int nonDecimal = fraction[0]/fraction[1];
	fraction[0] %= fraction[1];
	return nonDecimal;
}

void markRepetition(char *number, int index, int length){//formats the string for printing
	//ikiden indexe kadar basa
	for(int i=2;i<index;i++){
		number[i-2] = number[i];
	}
	number[index-2] = '[';
	for(int i=0;i<length;i++){
		number[i+index-1] = number[i+index];
	}
	number[length+index-1] = ']';
	number[length+index] = '\0'; //dont read beyond this
}

int main(int argc, char **argv)
{
	int fraction[2]; //to hold num and den
	int nonDecimal =0; //hold the non-decimal part 
	printf("Please enter the numerator and the denominator respectively\n");
	scanf("%d %d", &fraction[0],&fraction[1]);
	if(fraction[0]>fraction[1]){ //if fraction >1
		nonDecimal = numBigger(fraction);
	}
	simplify(fraction); //Simplify  everything
	if(checkTwoFive(fraction[1])){ //if true, there is no repetition
		printf("%lf\n", nonDecimal + (double)fraction[0]/(double)fraction[1]);
		return 0; //end the program		
	}
	if(isDivbyFive(fraction[0]) || isDivbyTwo(fraction[1])){ //Check if the den is divisable by 2 or 5
		char *number = malloc(60*sizeof(char)); //array size is larger just in case
		sprintf(number,"%.55lf" ,(double)fraction[0]/(double)fraction[1]); //put the division value to the string "number". 55 is the longest a double can hold appearently
		markRepetition(number,findRepetition(number,60,lengthOfRepetition(fraction[1])),lengthOfRepetition(fraction[1]));
		printf("%d.%s\n",nonDecimal,number);
		
	}else{
		expandToNine(fraction);
		printf("%d.[%d]\n",nonDecimal,fraction[0]); //num is the repetition
	}
	
	
	return 0;
}
