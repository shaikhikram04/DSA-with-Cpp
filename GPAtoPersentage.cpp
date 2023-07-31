#include <iostream>
using namespace std;

int main()
{
	for (;;)
	{
		float gpa;
		cout << "Enter your GPA : ";
		cin >> gpa;
		if (gpa == 10)
			cout << "Above 80% \nGrade is O";
		else if (gpa >= 9.0 && gpa < 10.0)
			cout << "You got " << (gpa - 2.0) * 10 << "% \n"
				 << "Grade is A++";
		else if (gpa >= 8.0 && gpa < 9.0)
			cout << "You got " << (gpa - 2.0) * 10 << "% \n"
				 << "Grade is A";
		else if (gpa >= 7.0 && gpa < 8.0)
			cout << "You got " << (gpa * 10 - ((gpa / 2) - 2) * 10) << "% \n"
				 << "Grade is B++";
		else if (gpa >= 6.0 && gpa < 7.0)
			cout << "You got " << (gpa * 10 - ((gpa / 2) - 2) * 10) << "% \n"
				 << "Grade is B";
		else if (gpa >= 5.0 && gpa < 6.0)
			cout << "You got " << (gpa * 10 - ((gpa / 2) - 2) * 10) << "% \n"
				 << "Grade is C";
		else if (gpa >= 4.0 && gpa < 5.0)
			cout << "You got " << (gpa * 10 - ((gpa / 2) - 2) * 10) << "% \n"
				 << "Grade is C";
		else
			cout << "Please enter GPA i.e from 4.0 to 10";
		cout << endl
			 << endl;
	}
	return 0;
}