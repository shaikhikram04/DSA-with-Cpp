#include <iostream>
using namespace std;

int main()
{
	int price;
	float discount_price;
	while (1)
	{
		cout << "Enter price : ";
		cin >> price;
		discount_price = price - (price * 0.28);
		cout << "Price after reduce 28% --> " << discount_price << endl
			 << endl;
	}
	return 0;
}