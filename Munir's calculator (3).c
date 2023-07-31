#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Functions Declaration:
int strLen(char str[]);
double calculate(char mainStr[]);
char replaceChar(char *str2, char a, char b);
int floatLen(float a);
double braces1(char mainStr[]);


//  Test cases:
//  456+6523*5214+5412*5412
//  4521-65*25-54+6523*9856/45+56-85
//  25143+6523*25+65(5214+65)/2+4
//  5214-956+658*85(452+23*85+65)(2)+65
//  4521+6523(541+65(23+12)62)+50
//  4521+6523(541+65(23+12)/62)+50
//  5(6+4-2(4+1)+2)+1
//  5413+652(5412+65(54+(89*2)+26+6)54)52
//  5(6+4-2(4+(89*2)51)+2)+1
//  5214+5(56(4+5)54+6(54+(65+5)*84)/5+8)+2


int main(void)
{
    char str[40];
    printf("Enter:");
    scanf("%s", str);

    printf(" \n\nANSWER:  %lf", calculate(str));
    return 0;
}

//Functions:
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
    printf("\nEntered MainStr is %s",mainStr);

    for (i = 0; i < strlen; i++)
    {
        if (mainStr[i] == '+' || mainStr[i] == '-' || mainStr[i] == '*' || mainStr[i] == '/' || mainStr[i] == '(' || mainStr[i] == ')')
        {
            for (j = 0; j < strlen; j++)
            {
                if (mainStr[j] == '(')
                {
                    return braces1(mainStr);
                    break;
                 }
            }

            for (j = 0; j < strlen; j++)
            {
                if (mainStr[j] == '+')
                {
                    printf("\nAddition Operation Starts:");
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
                if (mainStr[j] == '-'){
                printf("\nSubract operation Starts:");
                
                    for (k = 0, m = 0; k < j; k++, m++)
                    {
                        str1[m] = mainStr[k];
                    }

                    str1[m] = '\0';

                    str2 = strtok(mainStr, "-");
                    str2 = strtok(NULL, "\0");
                  if(str2[0]!='-'){
                      replaceChar(str2, '+', '-');
                  }
                  else{
                      replaceChar(str2, '+', '-');
                      str2[0]='-';
                  }
                   if(str1[m-1]=='*'){
                    printf("FLAG");
                    str1[m-1]='\0';
                 return -(calculate(str1)*calculate(str2));
                      
                   }
                   else if(str1[m-1]=='/'){
                    str1[m-1]='\0';
                    return -(calculate(str1)/calculate(str2));
                   }

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
                    printf("\nMultiplication Operation starts: ");
                    for (k = 0, m = 0; k < j; k++, m++)
                    {
                        str1[m] = mainStr[k];
                    }

                    str1[j] = '\0';

                    str2 = strtok(mainStr, "*");
                    str2 = strtok(NULL, "\0");


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
                    printf("\nDivision Operation Starts:");
                    for (k = 0, m = 0; k < j; k++, m++)
                    {
                        str1[m] = mainStr[k];
                    }

                    str1[j] = '\0';

                    str2 = strtok(mainStr, "/");
                    str2 = strtok(NULL, "\0");

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

double braces1(char mainStr[]){
    int i,j,k,m;
    int lastIndex;
    char tempStr[40];
    char str1[40];
    char str2[40];
    char str3[40];
    double z;
    printf("\nEntered Braces with Str %s",mainStr);
    for(i=0;i<strLen(mainStr);i++){
        if(mainStr[i]=='('){
            lastIndex=i;

        }
        
    }
    for(i=lastIndex+1,k=0;mainStr[i]!='\0';i++,k++){
        tempStr[k]=mainStr[i];
    }
        tempStr[k]='\0';
    for(i=0;tempStr[i]!='\0';i++){
        if(tempStr[i]==')'){
            m=i;
            break;
        }
    }
    for(i=0;i<m;i++){
        str2[i]=tempStr[i];
    }
    str2[i]='\0';
    if(tempStr[m+1]!='+'&&tempStr[m+1]!='-'&&tempStr[m+1]!='/'&&tempStr[m+1]!='*'){
        str3[0]='*';
        for(i=m+1,j=1;tempStr[i]!='\0';i++,j++){
            str3[j]=tempStr[i];

        }
        str3[j]='\0';
        

    }
    else{

    
    for(i=m+1,j=0;tempStr[i]!='\0';i++,j++){
        str3[j]=tempStr[i];
    }
    str3[j]='\0';
}

    for(i=0;i<lastIndex;i++){
        str1[i]=mainStr[i];
    }
                if (mainStr[lastIndex- 1] != '+' && mainStr[lastIndex - 1] != '-' && mainStr[lastIndex- 1] != '/')
            {
                str1[i] = '*';
                str1[i + 1] = '\0';
            }
            else
                str1[i] = '\0';

    printf("\nstr1:%s\nstr2:%s\nstr3:%s\nTempStr:%s\n",str1,str2,str3,tempStr);
    z=calculate(str2);
    sprintf(str2,"%f",z);
    strcat(str1,str2);
    strcat(str1,str3);
    printf("\nconcatenated string is %s",str1);

    return calculate(str1);
    return 0;



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