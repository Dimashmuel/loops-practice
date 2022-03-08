#include<stdio.h>
#define MIN 1000
#define MAX 9999
#define FIBONACCI_LIMIT 20

int main()
{
	//question 1 - power between two integers
	int num1, num2,i,power=1;
	printf("enter 2 num to calculate power\n");
	scanf_s("%d%d", &num1, &num2);
	for ( i = 1; i <= num2; i++)
		power *= num1;
	printf("the power of %d^%d is :%d\n", num1, num2, power);

	//question 2 -write a program that the input real numbers until a negative number is received.
	//After the negative number, the program will print the The minimum and maximum value.
	float max, min, temp;
	printf("enter positive num\n");
	scanf_s("%f", &temp);
	max = min = temp;
	while (temp >= 0)
	{
		scanf_s("%f", &temp);
		if (max < temp)
			max = temp;
		if (min > temp && temp >= 0)
			min = temp;
	}
	if (max == min && max > 0)
		printf("the max and min same value:%.2f\n", max);
	else if (max > 0 && min >= 0)

		printf("the max value is :%.2f\nthe min value is:%.2f\n", max, min);
	else
		printf("you input only nagtive num\n");
	//question 3 - how much number with 4 digit under the following three conditions: 
	//1)divide by 7- without residue.
	//2)divide by 11 with a remainder of 2 or 3
	//3)their unity digit is not 8
	int  count3 = 0;
	for ( i = MIN; i <= MAX; i++)
	{
		if (i % 7 == 0 && (i % 11 == 2 || i % 11 == 3) && i / MIN != 8)
			count3++;
	}
	printf("the count of number between %d - %d that meets the conditions :%d\n", MIN, MAX, count3);
	//question 4 - print the first 20 numbers of the Fibonacci series.
	int  fibonacci, a1 =0, a2 = 1,a3;
	printf("first %d fibonacci series :\n1)%d\n2)%d\n", FIBONACCI_LIMIT, a1, a2);
	for ( i = 1; i <=FIBONACCI_LIMIT; i++)
	{
		a3 = a1 + a2;
		printf("%d)%d\n",i, a3);
		a1 = a2;
		a2 = a3;
	}
	//question 5 - Write a program that captures a list of ascending numbers.
	//The list ends when an invalid number is entered(smaller than the previous member).
	//The program must print much numbers receivedand and their actual average.
	int count1=1,sum=0,numOne,numTwo;
	printf("enter positive ascending integers numbers(to end the program, enter smaller number then its predecessor)\n");
	scanf_s("%d%d",&numOne,&numTwo);
	if (numOne < 0)
		printf("worng in put!!!\n");
	else if (numOne > numTwo)
		printf("count:%d average:%.2f\n", count1, (float)numOne);
	else
	{
		sum = numOne;
		while (numOne <= numTwo)
		{
			count1++;
			sum += numTwo;
			numOne = numTwo;
			scanf_s("%d", &numTwo);
		}
		printf("count:%d average:%.2f\n", count1, (float)sum/count1);
	}
	//question 6 -
	int menu;
	printf("choose from menu for positive integer number\n1)show all even number from zero to the number\n2)show all prime number from 2 to the number\n");
	scanf_s("%d", &menu);
	switch(menu)
	{
	case 1:
	{
		int num, i;
		printf("enter positive integer number\n");
		scanf_s("%d", &num);
		for ( i = 0; i <= num; i++)
		{
			if (i%2==0)
				printf("%d\n",i);
		}
		break;
	}
	case 2:
	{
		int num,i, j,flag;
		printf("enter positive integer number bigger than 2\n");
		scanf_s("%d", &num);
		if (num < 2)
			printf("worng input\n");
		else
		{
			printf("the all prime number from 2 to the %d is \n", num);
			for (i = 2; i <= num; i++)
			{
				if (num % i != 0)
				{
					flag = 1;
					for (j = 2; j <= i / 2; j++)
					{
						if (i % j == 0)
						{
							flag = 0;
							break;
						}
					}
					if (flag == 1)
					{
						printf("%d\n", i);
					}
				}
			}
		}
	}
	break;
	default:
		printf("worng choose\n");
		break;
	}
	//question 7 - "perfect number"
	int sum1,j;
	printf("all perfect number from 1 to 10000:\n");
	for ( i = 1; i <10000; i++)
	{		
		sum1 = 0;
		for ( j = 1; j <i; j++)
		{
			if (i % j == 0)
				sum1 += j;
		}
		if (sum1 == i)
			printf("%d\n", i);
	}
	//question 8 -Write a program that captures pairs of integers and positives.
	//Each pair consists of a first number of 5 digits and a second number of one digit.
	//The single digit that is in the second number represents the digit that needs to be subtracted from everything that appears in the first number.
	//	The program must print, after receiving each pair, the new first number without the digit from the second number.
	int fiveDigit,oneDigit, newNum,temp1,count2=0;
	printf("enter a positive five-digit number\n");
	scanf_s("%d", &fiveDigit);
	printf("enter a number from one to nine\n");
	scanf_s("%d", &oneDigit);
	
	for ( i = 1; i <=5; i++)
	{
		temp1 =fiveDigit%10;
		if (temp1!=oneDigit)
		{
			count2++;
			if (count2 == 1)
				newNum = temp1;
			if (count2 == 2)
				newNum += (temp1*10);
			if (count2 == 3)
				newNum += (temp1 * 100);
			if (count2 == 4)
				newNum += (temp1 * 1000);
			if (count2 == 5)
				newNum += (temp1 * 10000);
		}
		fiveDigit /= 10;
	}
	printf("the new number is :%d\n", newNum);
	return 0;
}