#include <iostream>
#include "Polynomial.h"
using namespace  std;
int main()
{
	cout << "input max degree of first polynomial = ";
	int MaxDeg1;
	cin >> MaxDeg1;
	Polynomial a(MaxDeg1);
	int MaxDeg2;
	cout << "input max degree of second polynomial = ";
	cin >> MaxDeg2;
	Polynomial b(MaxDeg2);
	a.SetCoefficients(cin);
	cout << endl;
	cout << endl;
	a.GetCoefficients(cout);
	cout << endl; cout << endl;
	b.SetCoefficients(cin);
	cout << endl;
	cout << endl;
	b.GetCoefficients(cout);
	cout << endl << "Multiplication :    "<<endl;
	Polynomial c= a * b;
	c.GetCoefficients(cout);
	cout << endl << "Add :    " << endl;
	Polynomial d = a + b;
	d.GetCoefficients(cout);
	cout << endl << "Difference :    " << endl;
	Polynomial e = a - b;
	e.GetCoefficients(cout);
	double A1;
	double B1;
	double A2;
	double B2;
	double step;
	cout <<endl<< " input the limits of segment : \n A = ";
	cin >> A1;
	cout << endl << "B = " << endl;
	cin >> B1;
	cout <<endl<< "input step" << endl;
	cin >> step;
	A2 = A1;
	B2 = B1;
	cout << "first polynomial :     " << endl << endl;
	while(A1 <= B1)
	{
		cout << " in point " << A1 << "  " << a.ValueAtPoint(A1) << endl;
		A1 += step;
	}

	cout << endl << endl << "second polynomial :     " << endl << endl;;
	while (A2 <= B2)
	{
		cout << " in point " << A2 << "  " << b.ValueAtPoint(A2) << endl;
		A2 += step;
	}
	if(a==b)
	{
		cout << "a = b input the point to find value of derivative at  point : " << endl;
		double p;
		cin >> p;
		a.Derivative();
		cout << endl;
		a.GetCoefficients(cout);
		cout << endl;
		cout << a.ValueAtPoint(p) << endl;
		b.Derivative();
		cout << endl;
		b.GetCoefficients(cout);
		cout << endl;
		//b.ValueAtPoint(p);
		cout << b.ValueAtPoint(p) << endl;
	}
	else
	{
		cout << "input multiplier :  " << endl;
		double multiplier;
		cin >> multiplier;
		a.GetCoefficients(cout);
		cout << endl;
		Polynomial k = a*multiplier;
		a.GetCoefficients(cout);
		cout << endl;
		b.GetCoefficients(cout);
		cout << endl;
		Polynomial f = b * multiplier;
		b.GetCoefficients(cout);
		cout << endl;
		system("pause");
	}
	system("pause");
	return 0;
}