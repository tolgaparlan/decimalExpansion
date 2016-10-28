#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkTwoFive(int num){//checks if the number is in 2^a * 5^b form
	while(num%5==0 && num>0){//divides until can no more be divided
		num /= 5;
	}
	while(num%2==0 && num>0){//divides until can no more be divided
		num /= 2;
	}
	return (num==1 ? 1: 0); //1 if valid, 0 if not
}

int lengthOfRepetition(int n){ //finds the length of the repetition
	int value=1 ,length=0;	
	while(n%2==0 && n>0){
		n /= 2;
	}
	while(n%5==0 && n>0){//makes sure not divisable by 2 or 5
		n /= 5;
	}
	
    do{
		value = value *10;
		value = value % n;
		length++;
    }while (value != 1); //checks after how many steps 'value' returns to what it started as 	
    return length;
}

void Cosimplify(unsigned long *fraction){	//simply den and num until they are co-primes
	for(int i=2;i<=fraction[0]/2;i++){ //fraction[0] is the numerator. assume that den is always bigger
		while(fraction[0]%i==0 && fraction[1]%i==0){
			fraction[0] /= i;
			fraction[1] /= i;
		}
	}
}

int findRepetition(char *number, int lenRep){//takes the decimal point string and length of repetition as input. returns the index the repetition starts
	int match;//stores number of same chars
	for(int i=0;i<lenRep*3;i++){ //because of the dot character, non-decimal points will never be mistaken
		match=0;
		for(int j=0;j<lenRep;j++){//check the series for each digit
			if(number[i+j]==number[i+j+lenRep]){ //check if repeats
				match++;
			}
		}
		if(match==lenRep){//if all the repeating digits were present.
			return i; //return the index repetition starts
		}
	}
	return -1; //there is a problem (no repetition?)
}

int makeDenBigger(unsigned long *fraction){//if the num is bigger than den
	int nonDecimal = fraction[0]/fraction[1];
	fraction[0] %= fraction[1];
	return nonDecimal;
}

void markRepetition(char *number, int index, int length){//formats the string for printing
	if(index==-1){ //in some cases where length==1, index may not be found. 
		index=strlen(number)-1;
	}
	for(int i=length;i>0;i--){
		number[i+index] = number[i+index-1];
	}	
	number[index] = '[';
	number[length+index+1] = ']';
	number[length+index+2] = '\0'; //dont read beyond this
}

void longDivision(unsigned long *fraction, char* number, int lenRep){//applies long division and puts results in a char array
	
    int remainder = 0,num = fraction[0],den = fraction[1],tracker;

    for(int i=0;i<lenRep*3;i++){		
		tracker=0;
		while(num<den){
			num *= 10;
			if(tracker){
				number[i]= 0 + '0';
				i++;
			}
			tracker++;
		}
		remainder = num %den; 
		number[i] = num/den + '0';
		num = remainder;
	}
	number[lenRep*3] = '\0';
}

int main(int argc, char **argv)
{
	unsigned long fraction[2]; //to hold num and den
	int nonDecimal =0; //hold the non-decimal part 
	int lenRep; //length of repetition
	printf("Please enter the numerator and the denominator respectively seperated by a space\n");
	scanf("%lu %lu", &fraction[0],&fraction[1]);
	if(fraction[0]>fraction[1]){ //if fraction >1
		nonDecimal = makeDenBigger(fraction);
	}
	Cosimplify(fraction); //Simplify  everything
	if(checkTwoFive(fraction[1])){ //if true, there is no repetition
		printf("%g\n", nonDecimal + (double)fraction[0]/(double)fraction[1]);	
	}else{ //there is repetition
		lenRep = lengthOfRepetition(fraction[1]);	
		char *number = malloc(lenRep*3*sizeof(char)); //3 times the length of repetition just to be safe
		longDivision(fraction,number,lenRep);
		markRepetition(number,findRepetition(number,lenRep),lenRep);
		printf("%d.%s\n",nonDecimal,number);
		free(number);
	}
	
	return 0;
}
