#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(char str[]);
double calculate(char mainStr[]);
char replaceChar(char *str2, char a, char b);
int floatLen(float a);

//  Test cases:

//  456+6523*5214+5412*5412
//  4521-65*25-54+6523*9856/45+56-85
//  25143+6523*25+65(5214+65)/2+4
//  5214-956+658*85(452+23*85+65)(2)+65
//  5(6+4-2(4+1)+2)+1

int main(void)
{
	char str[40];
	printf("Enter:");
	scanf("%s", str);

	printf(" \n\nANSWER:  %lf", calculate(str));
	return 0;
}
double calculate(char mainStr[40])
{
	int i, j, m, k;
	double x, y, z;

	int flag;
	char str1[40];
	char *str2;
	char *str3;
	char str4[35];
	int str4len;
	char sw, ch = '*';

	int strlen = strLen(mainStr);
	if (mainStr[strlen] == '+' || mainStr[strlen] == '-' || mainStr[strlen] == '*' || mainStr[strlen] == '/')
	{
		mainStr[strlen] = '*';
		mainStr[strlen + 1] = '1';
	}

	if (mainStr[0] == '+' || mainStr[0] == '-' || mainStr[0] == '*' || mainStr[0] == '/')
	{
		mainStr[0] = '0';
	}
	for (i = 0; i < strlen; i++)
	{
		if (mainStr[i] == '+' || mainStr[i] == '-' || mainStr[i] == '*' || mainStr[i] == '/' || mainStr[i] == '(' || mainStr[i] == ')')
		{
			for (j = 0; j < strlen; j++)
			{
				if (mainStr[j] == '(')
				{
					for (k = 0, m = 0; k < j; k++, m++)
					{
						str1[m] = mainStr[k];
					}
					str1[j] = '\0';
					printf(" str1 is %s", str1);
					str2 = strtok(mainStr, "(");
					str2 = strtok(NULL, ")");
					printf(" str2 is %s", str2);

					str3 = strtok(NULL, "\0");
					printf(" str3 is %s", str3);

					z = calculate(str2);

					str4len = floatLen(z);
					gcvt(z, str4len + 5, str4);

					sw = str1[j - 1];
					printf(" char is %c", sw);

					if (sw != '+' && sw != '-' && sw != '/')
					{
						//swtich
						strncat(str1, &ch, 1);
					}
					if (str3[0] != '+' && str3[0] != '-' && str3[0] != '/')
					{
						strncat(str4, &ch, 1);
					}

					strcat(str1, str4);
					strcat(str1, str3);
					printf(" str1 is %s", str1);

					return calculate(str1);
				}
			}

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
					replaceChar(str2, '+', '-');
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
char replaceChar(char *str2, char a, char b)
{
	int i;
	int strlen = strLen(str2);
	for (i = 0; i < strlen; i++)
	{
		if (str2[i] == a)
		{
			str2[i] = b;
		}
		if (str2[i] == b)
		{
			str2[i] = a;
		}
	}
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
int floatLen(float a)
{
	int d, c = 0, b;
	b = a;

	while (b != 0)
	{
		b = b / 10;
		c++;
	}
	return c;
}