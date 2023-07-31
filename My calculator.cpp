#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  test cases

// ✓  10+11+12+5-8-12
// ✓  456+6523*5214+5412*5412
// ✓  4521-65*25-54+6523*9856/45+56-85
// ✓  2+5*(6+4-2*(4+1)+2)+1
// ✓  5214-956+658*85*(452+23*85+65)*(2)+65
// ✓  5*(6+4-2*(4+(89*2)*51)+2)+1
// ✓  5(6+4-2(4+(89*2)51)+2)+1
// ✓  25143+6523*25+65(5214+65)/2+4
// ✓  4521+6523(541+65(23+12)62)+50
// ✓  4521+6523(541+65(23+12)/62)+50
// ✓  5(6+4-2(4+1)+2)+1
// ✓  5413+652(5412+65(54+(89*2)+26+6)54)52
// ✓  5214+5(56(4+5)54+6(54+(65+5)*84)/5+8)+2

double calculate(string str);

string concatbrkt(string str, int &s)
{
	string rtrnStr;
	int count1 = 0, count2 = 0;
	for (; s < str.size(); s++)
	{
		rtrnStr.push_back(str[s]);
		if (str[s] == '(')
		{
			count1++;
		}
		else if (str[s] == ')')
		{
			count2++;
			if (count1 == count2)
			{
				break;
			}
		}
	}
	return rtrnStr;
}

double strToDbl(string str)
{
	double ans = 0.0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			int j=1;
			for(i++;i<str.size();i++,j++)
			{
				ans+=(str[i] - '0')/pow(10,j);
			}
			break;
		}
		ans = ans * 10.0 + (str[i] - '0');
	}
	return ans;
}

double simplify(string operand)
{
	double result;
	vector<double> oprnd;
	string optr;
	string temp;
	for (int i = 0; i < operand.size(); i++)
	{
		if (operand[i] == '(')
		{
			if (operand[i - 1] >= '0' && operand[i - 1] <= '9')
			{
				oprnd.push_back(strToDbl(temp));
				temp.clear();
				optr.push_back('*');
			}

			int count1 = 1, count2 = 0;
			string bracPart;
			for (i = i + 1; i < operand.size(); i++)
			{
				if (operand[i] == '(')
				{
					count1++;
				}
				else if (operand[i] == ')')
				{
					count2++;
					if (count1 == count2)
						break;
				}
				bracPart.push_back(operand[i]);
			}
			oprnd.push_back(calculate(bracPart));

			if (operand[i + 1] >= '0' && operand[i + 1] <= '9')
				optr.push_back('*');
		}

		else if (operand[i] != '*' && operand[i] != '/')
		{
			temp.push_back(operand[i]);
			if (i == operand.size() - 1)
			{
				oprnd.push_back(strToDbl(temp));
				temp.clear();
			}
		}
		else if (operand[i] == '*' || operand[i] == '/')
		{
			if (!temp.empty())
			{
				oprnd.push_back(strToDbl(temp));
				temp.clear();
			}
			optr.push_back(operand[i]);
		}
	}

	int index = optr.find('/');
	while (index >= 0 && index < optr.size())
	{
		oprnd[index + 1] = oprnd[index] / oprnd[index + 1];
		optr.erase(index);
		oprnd.erase(oprnd.begin() + index);
	}

	result = oprnd[0];
	for (int i = 1; i < oprnd.size(); i++)
	{
		result = result * oprnd[i];
	}

	return result;
}

void checkToSimplify(string operand, double &o)
{
	int index1 = operand.find('*');
	int index2 = operand.find('/');
	int index3 = operand.find('(');
	if (index1 != -1 || index2 != -1 || index3 != -1)
	{
		o = simplify(operand);
	}
	else
	{
		o = strToDbl(operand);
	}
}

double calculate(string str)
{
	double result;
	string operand1;
	string operand2;
	double op1, op2;
	char optr;

	// making operand 1
	int i = 0;
	while (str[i] != '+' && str[i] != '-' && i < str.size())
	{
		if (str[i] == '(')
		{
			string temp = concatbrkt(str, i);
			operand1 += temp;
		}
		else
		{
			operand1.push_back(str[i]);
		}
		i++;
	}

	checkToSimplify(operand1, op1);

	// making operand 2
	for (; i < str.size(); i++)
	{
		optr = str[i];
		i++;
		while (str[i] != '+' && str[i] != '-' && i < str.size())
		{
			if (str[i] == '(')
			{
				string temp = concatbrkt(str, i);
				operand2 += temp;
			}
			else
			{
				operand2.push_back(str[i]);
			}
			i++;
		}

		checkToSimplify(operand2, op2);

		operand2.clear();
		if (optr == '+')
			op1 = op1 + op2;
		else
			op1 = op1 - op2;
		i--;
	}
	result = op1;
	return result;
}

int main()
{
	string str;
	cout << "Enter a string : " << endl;
	getline(cin, str);
	cout << "\nResult --> " << fixed << calculate(str) << endl;
	return 0;
}