# decimalExpansion
We expand decimals and shit.

#--Websites we checked--
http://eli.thegreenplace.net/2009/02/25/project-euler-problem-26/
http://mathworld.wolfram.com/DecimalExpansion.html
http://stackoverflow.com/questions/1315595/algorithm-for-detecting-repeating-decimals

#--Function list--

DONE *Simplify the denominator/numerator as much as we can
DONE *Check if den is in (2^a)*(5^b) form
DONE *Check if den is divisable by 2 and 5
DONE *Check for 10^k = 1(mod n), k=length of repetation, n=biggest prime divisor of den
DONE *Find the biggest prime divisor of a number
*iteratively find the repetition

#IDEAS AND SHIT
*we can carry numerator and denominator around in an array. would be easy to reach and manipulate in functions
*we should also plan for the cases where numerator is bigger than the denominator
*we can also make it so that when the program is called like "repetitionFinder num den" in the command line, it automatically outputs the output