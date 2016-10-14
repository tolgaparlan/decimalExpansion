# decimalExpansion
We expand decimals and shit.

#--Websites we checked--
http://eli.thegreenplace.net/2009/02/25/project-euler-problem-26/<br />
http://mathworld.wolfram.com/DecimalExpansion.html<br />
http://stackoverflow.com/questions/1315595/algorithm-for-detecting-repeating-decimals<br />

#--Function list--

DONE *Simplify the denominator/numerator as much as we can <br />
DONE *Check if den is in (2^a)*(5^b) form <br />
DONE *Check if den is divisable by 2 and 5 <br />
DONE *Check for 10^k = 1(mod n), k=length of repetation, n=biggest prime divisor of den<br />
DONE *Find the biggest prime divisor of a number<br />
DONE *iteratively find the repetition<br />
DONE *expand den and num until den is in a form of all 9s<br />
DONE *handle it if num>den

#IDEAS AND SHIT
*we can carry numerator and denominator around in an array. would be easy to reach and manipulate in functions<br />
*we should also plan for the cases where numerator is bigger than the denominator<br />
*we can also make it so that when the program is called like "repetitionFinder num den" in the command line, it automatically outputs the output<br />
*take a look at the sprintf function. We can probably use it to search for repetitions, as a char array might be very useful. Note  that we can manipulate the format string of the function (second argument), by giving a string of our choice. I think we will need this when we deal with numbers with long repetitions etc<br />

#ROAD MAP
1)Simplify  everything<br />
2)Check if the den is in (2^a)*(5^b) form. If so, go to STEP 3. Otherwise go to STEP 4<br />
3)There is no repetition and we can just print the result of the division<br />
4)Check if the den is divisable by 2 or 5. If so, go to STEP 6. Otherwise go to STEP 5 <br />
5)Expand the den and num until the den is in an all 9s form. The num will be the repetition<br />
6)10^k = 1(mod n) to find the k=length of repetition<br />
7)Make the division result a char array (sprintf()?) and search for the repetition, as we know the length of repetition now.


