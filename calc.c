/*
Author: Michelle Allison
Description: This program is similar to a calculator-- 2 numbers are entered and an operator is chosen that performs a calculation and gives the user an answer.

I prefer the Virtual Box for grading.
*/

#include<stdio.h>

int main(void){

char command = ' ';
double EARLIER = 0;
double LATER = 0;
double tmp = 0;
int status = 0;
double EARLIERpow = 0;
double LATERpow = 0;

while (command != 'q') {
	status = scanf("%lf",&tmp); //status is meant to show whether the character entered is a double or not.
	if (status == 1) { // if the character's a double, it's saved into LATER.
		EARLIER = LATER;
		LATER = tmp;
	} else { // if the character's something else, it checks if it's a command or an invalid operator.
		if (EOF == scanf("%c",&command)){
			command = 'q'; //if EOF, program quits
		} else {
			if (command == 'p') { //'p' prints the 2 numbers the program is working with currently
				printf("%.3lf\n", EARLIER);
				printf("%.3lf\n", LATER);
			}
			if (command == 'a') { // 'a' adds the numbers
				LATER = LATER + EARLIER;
				printf("=%.3lf\n", LATER);
			}
			if (command == 's') { // 's' subtracts the numbers
				LATER = LATER - EARLIER;
				printf("=%.3lf\n", LATER);
			}
			if (command == 'x') { // 'x' multiplies the numbers
				LATER = LATER * EARLIER;
				printf("=%.3lf\n", LATER);
			}
			if (command == 'd') { // 'd' divides the numbers, but checks if the denominator is 0 first.
				if (EARLIER < 0.000001 && EARLIER > -0.000001) {
					printf("Divide by zero error.\n");
					continue;
				}
				LATER = LATER / EARLIER;
				printf("=%.3lf\n", LATER);
			}
			if (command == '^') { // '^' is a power function-- LATER^EARLIER. It only does integer powers (because I assume we weren't supposed to use the pow function) and it distinguishes between positive, 0, and negative powers.
				if (EARLIER > 1) {
					EARLIERpow = EARLIER;
					LATERpow = LATER;
					for (; EARLIERpow > 1; EARLIERpow--) {
						LATER = LATER * LATERpow;
					}
				}
				if (EARLIER == 0) {
					LATER = 1;
				}
				if (EARLIER < 0) { // if EARLIER is negative, do 1/LATER (because that's how power works) and make EARLIERpow positive so it can work with the for loop
					LATER = 1 / LATER;
					EARLIERpow = -1 * EARLIER;
					LATERpow = LATER;
					for (; EARLIERpow > 1; EARLIERpow--) {
						LATER = LATER * LATERpow;
					}					
				}
				printf("=%.3lf\n", LATER);
			}
			if (command == 'w') { // 'w' switches EARLIER and LATER.
				tmp = EARLIER;
				EARLIER = LATER;
				LATER = tmp;
			}
			if (command == 'c') { // 'c' clears EARLIER and LATER.
				LATER = 0.0;
				EARLIER = 0.0;
			}
			if (command == 'h') { // 'h' tells the user what each command is and what it does.
				printf("Help:\na adds both numbers together.\ns subtracts the second latest number you've entered from the latest number you've entered.\np prints the latest numbers you've entered.\nx multiplies both numbers.\nd divides the latest number you've entered by the second latest number you've entered.\n^ computes the latest number you've entered to the power of the second latest number you've entered.\nw switches the number values.\nc clears both held values.\ny makes the latest number you've entered negative.\nh summons the help menu.\nq quits the program.\n");
			}
			if (command != 'q' && command != 'a' && command != 's' && command != 'p' && command != 'x' && command != 'd' && command != '^' && command != 'w' && command != 'c' && command != 'h' && command != 'y') { // if the character entered isn't a valid command, it tells the user the operator isn't supported.
				printf("The operator %c is not supported.\n", command);
			}
			if (command == 'y') { // this is my operator-- it makes LATER negative. I'm not very creative.
				LATER = -1.0 * LATER;
			}
		}
	}

}

printf("%.3lf\n", EARLIER); // prints EARLIER and LATER after 'q' is pressed.
printf("%.3lf\n", LATER);


return 0;
}
