/* RILEY JOHNSON ****
** LAB ASSIGNMENT 2 *
** 9/6/18 ***********
** 10257985 *********
*********************/

//INCLUDED HEADER FILES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

//FUNCTION DEFINITIONS
void displayMAIN();
void displayMenu();
void displayBinaryMenu();
int menuFunc(char);
int binaryFunc(char);
void factorialFunc();
void leapYearFunc();
void maximum();
void division();
void binalg();
void binbit();

int main(){
	
	int mainFlag = 1;
	int menuFlag = 1;
	int binaryFlag = 1;

	char mainUserInput;
	char menuUserInput;
	char binaryUserInput;

	//LOOPS UNTIL USER EXITS
	while (mainFlag == 1){
		displayMAIN();
		scanf(" %1c", &mainUserInput);
		switch(mainUserInput){
			//USER SELECTS MENU FOR PROBLEM 1 IN LAB ASSN.
			case '1':
				displayMenu();
				scanf(" %1c", &menuUserInput);
				mainFlag = menuFunc(menuUserInput);
				break;
			//USER SELECTS MENU FOR BINARY CONVERSIONS
			case '2':
				displayBinaryMenu();
				scanf(" %1c", &binaryUserInput);
				mainFlag = binaryFunc(binaryUserInput);
				break;
			//EXIT AND CLOSE SOFTWARE
			case '3':
				printf("\nSoftware Will Now Exit. Thank you\n");
				mainFlag = 0;
				break;
			//INVALID INPUT. LOOPS BACK TO MENU
			default:
				printf("\nSoftware Did Not Recognize Your Input\n");
		}
	}
	return 0;
}

//DISPLAYS MAIN MENU CHOICES
void displayMAIN(){
	printf("\n----------- MAIN MENU -----------");
	printf("\n\t[1] Various Calculations");
	printf("\n\t[2] Binary Representation");
	printf("\n\t[3] Exit");
	printf("\nSelection: ");
}

//DISPLAYS MENU FOR VARIOUS CALCULATIONS (PROBLEM 1)
void displayMenu(){
	printf("\n******** MENU ********");
	printf("\n\t[A] Factorial");
	printf("\n\t[B] Leap Year");
	printf("\n\t[C] Maximum");
	printf("\n\t[D] Division");
	printf("\n\t[E] Return To Main Menu");
	printf("\n\t[F] Exit");
	printf("\nSelection: ");
	
}

//DISPLAYS BINARY CONVERSION MENU
void displayBinaryMenu(){
	printf("\n****** BINARY REPRESENTATION ******");
	printf("\n\t[A] Arithmetic Computation");
	printf("\n\t[B] Bitwise Computation");
	printf("\n\t[C] Return To Main Menu");
	printf("\n\t[D] Exit");
	printf("\nSelection: ");
}

//FUNCTION TO REDIRECT USER BASED ON SELECTION. RECEIVES "CHOICE".
//RETURNS 1 ON SUCCESS. RETURNS 0 TO EXIT MENU AND RETURN TO MAIN.
int menuFunc(char choice){
	int loopflag = 1;
	choice = toupper(choice);
	while (loopflag == 1){
		switch (choice){
			//USER ENTERS 'A' FOR FACTORIAL CALCULATION
			case 'A':
				factorialFunc();
				return 1;
				break;
			//USER ENTERS 'B' FOR LEAP YEAR CALCULATION
			case 'B':
				leapYearFunc();
				return 1;
				break;
			//USER ENTERS 'C' TO FIND MAXIMUM OF TWO NUMBERS
			case 'C':
				maximum();
				return 1;
				break;
			//USER ENTERS 'D' TO DIVIDE TWO NUMBERS
			case 'D':
				division();
				return 1;
				break;
			//RETURN TO MAIN MENU
			case 'E':
				return 1;
				break;
			//EXIT AND CLOSE SOFTWARE
			case 'F':
				return 0;
				break;
			default:
				printf("\nSoftware Did Not Recognize Your Input\n");
		}
	}
	return 0;
}
//FUNCTION TO REDIRECT USER BASED ON BINARY MENU SELECTION. RECEIVES "CHOICE".
//RETURNS 1 ON SUCCESS. RETURNS 0 TO EXIT MENU AND RETURN TO MAIN.
int binaryFunc(char choice){
	int loopflag = 1;
	choice = toupper(choice);
	while (loopflag == 1){
		switch (choice){
			//USER ENTERS 'A' FOR BINARY CONVERSION USING ARITHMETIC OEPRATIONS
			case 'A':
				binalg();
				return 1;
				break;
			//USER ENTERS 'B' FOR BINARY CONVERSION USING BIT SHIFTING
			case 'B':
				binbit();
				return 1;
				break;
			//RETURN TO MAIN MENU
			case 'C':
				return 1;
				break;
			//EXIT AND CLOSE SOFTWARE
			case 'D':
				return 0;
				break;
			default:
				printf("\nSoftware Did Not Recognize Your Input\n");
		}
	}
	return 0;
}

//RANGE FOR UNSIGNED LONG IS 0 - 4,294,967,295. LARGEST VALUE USER MAY ENTER IS 12! = 4.79E8.
//NEXT LARGEST FACTORIAL CAUSES OVERFLOW. FUNCTION CALCULATES FACTORIAL OF USER ENTERED VALUE.
void factorialFunc(){
	int n = 0;
	int loopflag = 1;
	unsigned short value = 0;
	unsigned long result = 0;

	//STAYS IN LOOP WHILE INVALID INPUT
	while (loopflag == 1){
		printf("\nEnter the digit to calculate it's factorial: ");
		scanf("%2hu", &value);
		if ((value > 12)||(value < 0)){
			printf("\nInput must be between 0 and 12");
		}
		else
			loopflag = 0; //BREAKS LOOP IF VALID INPUT RECEIVED
	}
	result = value;
	//MULTIPLIES ITSELF BY ITSELF - 1 UNTIL ZERO
	for (n = (value-1); n > 1; n--){
		result *= (unsigned long)n;
	}
	printf("\n%hu", value);
	printf("! = %lu\n", result);
}

//FUNCTION RECEIVES YEAR FROM USER (0 - 65,353) CHECKS IF LEAP YEAR OR NOT
void leapYearFunc(){
	unsigned int leapYear = 0;
	int loopflag = 1;

	//STAYS IN LOOP WHILE INVALID INPUT
	while (loopflag == 1){
		printf("\nEnter the year you would like to check: ");
		scanf("%6u", &leapYear);
		if ((leapYear <= 0)||(leapYear > 65535)){
			printf("\nPlease enter a valid year between 1 and 65,535 A.D.");
		}
		else
			loopflag = 0; //BREAKS IF VALID INPUT RECEIVED
	}

	if (((leapYear % 4 == 0)&&(leapYear % 100 != 0))||(leapYear % 400 == 0))
		printf("\nYear %u is a leap year\n", leapYear);
	else
		printf("\nYear %u is NOT a leap year\n", leapYear);
}

//FINDS MAXIMUM OF TWO ENTRIES USING "?" OPERATOR
void maximum(){
	float num1, num2, max;

	printf("\nEnter the first value to compare: ");
	scanf("%f", &num1);
	printf("\nEnter the second value to compare: ");
	scanf("%f", &num2);
	if (num1 == num2)
		printf("\nThe two values are equal\n");
	else{
		max = ((num1 > num2)? num1:num2);
		printf("\n%.2f is the greater of the two values: %.2f and %.2f\n", max, num1, num2);
	}
}

//DIVIDES TWO NUMBERS USING TYPECASTING. CHECKS IF DENOMINATOR IS ZERO
void division(){
	int op1, op2;
	float result = 0;

	printf("\nEnter the numerator: ");
	scanf("%d", &op1);
	printf("\nEnter the denominator: ");
	scanf("%d", &op2);
	//ENTERS LOOP IF OPERAND 2 IS ZERO. BREAKS WHEN NOT ZERO
	while (op2 == 0){
		printf("\nDenominator must not be zero. Enter a new denominator: ");
		scanf("%d", &op2);
	}
	result = (float)op1 / (float)op2;
	printf("\n%d / %d = %.2f\n", op1, op2, result);
}

//CONVERTS DECIMAL TO BINARY USING MATHEMATICAL EXPRESSIONS. MAINLY USES MODULO TO 
//DETERMINE IF ONE'S OR ZERO'S.
void binalg(){
	unsigned short dec, remain;
	int element = 0;
	int flag = 0;
	int bin[16] = {0}; //INITIALIZE RESULT TO ALL ZEROS

	while (flag == 0){
		printf("\nEnter a decimal number: ");
		scanf("%hu", &dec);
		if ((dec > 65535)||(dec < 0))
			printf("\nPlease enter a decimal number from 0 - 65535");
		else
			flag = 1;
	}
	printf("\n%hu -> ", dec);
	while (dec > 0){
		remain = dec % 2;
		bin[element] = remain;
		dec /= 2;
		element++;
	}
	element = 15;
	//PUTS A GAP BETWEEN GROUPS OF 8 BITS
	while (element >= 0){
		if (element == 7)
			printf(" ");
		printf("%d", bin[element]);
		element--;
	}
	printf("\n");
}

//CONVERTS DECIMAL TO BINARY USING BITWISE OPERATIONS (BITSHIFTING) ALONG WITH
//THE "AND" LOGICAL OPERATOR TO DETERMINE IF ONE'S OR ZERO'S.
void binbit(){
	unsigned short dec;
	int bitmask = 0x4000;
	int count = 0;
	int flag = 0;

	while (flag == 0){
		printf("\nEnter a decimal number: ");
		scanf("%hu", &dec);
		if ((dec > 65535)||(dec < 0))
			printf("\nPlease enter a decimal number from 0 - 65535");
		else
			flag = 1;
	}
	printf("\n%hu -> ", dec);
	if ((dec & 0x8000) == 0)
		printf("0");
	else
		printf("1");
	while (bitmask != 0){
		//PUTS A GAP BETWEEN GROUPS OF 8 BITS
		if (count == 7)
			printf(" ");
		count++;
		if ((dec & bitmask) == 0)
			printf("0");
		else
			printf("1");
		bitmask = bitmask >> 1;
	}
	printf("\n");
}
