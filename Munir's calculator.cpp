#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(char str[]);
double calculate(char mainStr[]);
//test cases
//456+6523*5214+5412*5412
//4521-65*25-54+6523*9856/45+56-85

int main(void)
{
	char str[40];
	char ex[30];
	char *res;
	printf("Enter String : ");
	scanf("%s", str);
	printf(" return value is %lf", calculate(str));

	return 0;
}
double calculate(char mainStr[40])
{
	int i, j, m, k;
	double x, y;
	int flag;
	char str1[40];
	char *str2;

	int strlen = strLen(mainStr);
	for (i = 0; i < strlen; i++)
	{
		if (mainStr[i] == '+' || mainStr[i] == '-' || mainStr[i] == '*' || mainStr[i] == '/')
		{
			for (j = 0; j < strlen; j++)
			{
				if (mainStr[j] == '+')
				{
					for (k = 0, m = 0; k < j; k++, m++)
					{
						str1[m] = mainStr[k];
					}

					str1[j] = '\0';

					str2 = strtok(mainStr, "+");
					str2 = strtok(NULL, "\0");

					printf("\n %s and  ", str1);
					printf("%s ", str2);
					x = calculate(str1);
					y = calculate(str2);
					printf("\n %lf + %lf = %f", x, y, x + y);

					return (x + y);
				}
			}
			for (j = 0; j < strlen; j++)
			{
				if (mainStr[j] == '-')
				{
					for (k = 0, m = 0; k < j; k++, m++)
					{
						str1[m] = mainStr[k];
					}

					str1[j] = '\0';

					str2 = strtok(mainStr, "-");
					str2 = strtok(NULL, "\0");

					printf("\n %s and  ", str1);
					printf("%s ", str2);
					x = calculate(str1);
					y = calculate(str2);
					printf("\n %lf - %lf = %f", x, y, x - y);

					return (x - y);
				}
			}
			for (j = 0; j < strlen; j++)
			{
				if (mainStr[j] == '*')
				{
					for (k = 0, m = 0; k < j; k++, m++)
					{
						str1[m] = mainStr[k];
					}

					str1[j] = '\0';

					str2 = strtok(mainStr, "*");
					str2 = strtok(NULL, "\0");

					printf("\n %s and  ", str1);
					printf("%s ", str2);
					x = calculate(str1);
					y = calculate(str2);
					printf("\n %lf x %lf = %lf", x, y, x * y);

					return (x * y);
				}
			}
			for (j = 0; j < strlen; j++)
			{
				if (mainStr[j] == '/')
				{
					for (k = 0, m = 0; k < j; k++, m++)
					{
						str1[m] = mainStr[k];
					}

					str1[j] = '\0';

					str2 = strtok(mainStr, "/");
					str2 = strtok(NULL, "\0");

					printf("\n %s and  ", str1);
					printf("%s ", str2);
					x = calculate(str1);
					y = calculate(str2);
					printf("\n %lf / %lf = %lf", x, y, x / y);

					return (x / y);
				}
			}
		}
	}
	return atof(mainStr);
}

int strLen(char str[40])
{
	int count = 1;
	while (str[count] != 0)
	{
		count++;
	}
	return count;
}