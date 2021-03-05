#include<iostream>
#include<string>
using namespace std;


int x = 0;
float z = 0;

struct market
{
	int ID, num_pices;
	string name;
	float price;
};


int add(market m[])
{
	cout << "enter the name of the product that you want to buy it:  ";
	cin >> m[x].name;
	for (int i = 0; i < x; i++)
	if (m[x].name == m[i].name)
	{
		cout << "\nit used,you must enter another name of product";
		add(m);
		return 0;
	}
	cout << "enetr the ID of product:  ";
	cin >> m[x].ID;
	cout << "enter the price of amount:  ";
	cin >> m[x].price;
	cout << "enter the amount of product:  ";
	cin >> m[x].num_pices;
	x++;
}


int del(market m[])
{
	string a;
	cout << "enter the name of product that you want delete it :  ";
	cin >> a;
	for (int i = 0; i < x; i++)
	{
		if (a == m[i].name)
		for (int i = 0; i < x - 1; i++)
			m[i] = m[i + 1];
		x--;
		cout << "\n";
		return 0;
	}
	cout << "this product doesn't exist\n";
	return 0;
}


void display(market m[])
{
	for (int i = 0; i < x; i++)
	{
		cout << "the name of product :  " << m[i].name << "\n";
		cout << "the ID of the product :  " << m[i].ID << "\n";
		cout << "the price of this product :  " << m[i].price << "\n";
		cout << "the amount of the product :  " << m[i].num_pices << "\n\n\n";
	}
}


double price(market m[])
{
	double pr = 0.0;
	for (int i = 0; i < x; i++)
		pr += m[i].price*m[i].num_pices;
	return pr;
}


double discound(market m[], float disc)
{
	double q;
	q = 0.0;
	for (int i = 0; i < x; i++)
		q += m[i].price*m[i].num_pices;
	return (q - (q*disc / 100));
}


int main()
{
	int s, r;
	market m[100];
	cout << "*****     *****\n";
	cout << "*** **   ** ***\n";
	cout << "***  ** **  ***\n";
	cout << "***    *    ***\n";
	cout << "***         ***\n\n\n";
	do
	{
		system("pause");
		system("CLS");
		cout << "\n 1:add item";
		cout << "\n 2:delete item";
		cout << "\n 3:display the list with item in the list";
		cout << "\n 4:show the total amount of the bill";
		cout << "\n 5:discount on the total amount";
		cout << "\n 6:exit\n";
		cout << "enter the number of command that you want it :  ";
		cin >> s;
		switch (s)
		{
		case 1:
			cout << "\n", add(m);
			break;
		case 2:
			cout << "\n", del(m), cout << "\n";
			break;
		case 3:
			cout << "\n", display(m), cout << "\n";
			break;
		case 4:
			cout << "\nthe total price = " << price(m), cout << "\n";
			break;
		case 5: {
					cout << "\nenter the discound percentage:  ";
					cin >> r;
					cout << "total price = " << price(m) << "\t" << "price after discounding " << discound(m, r) << endl;
					break;
		}

		case 6: {
					cout << "\n  you are welcome\n\n";
					cout << " **  **\n" << "*   *   *\n" << " *     *\n" << "  *  *\n" << "   *\n" << endl;
					cout << "  we hope you will come soon\n\n\n";
					system("pause");
					return 0; }
		default:
			cout << "please enter one of the previous choices " << endl;
		}
	} while (s != 6);
	return 0;
}