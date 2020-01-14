#pragma once
#include <iostream>
#include <fstream>
using namespace  std;
class Polynomial
{
private:
	double *coefficients;
	int maxDegree;
public:
	Polynomial();
	Polynomial(int _maxDegree);
	Polynomial(const Polynomial & other);
	~Polynomial();
	int GetMaxDegree()const;
	void SetMaxDegree(int _maxDegree);
	void SetCoefficients(istream & is);
	void GetCoefficients(ostream & os);
	friend Polynomial operator * (Polynomial &ob,double multiplier);
	Polynomial operator + (const Polynomial &other);
	Polynomial operator - (const Polynomial &other);
	Polynomial operator * (const Polynomial &other);
	Polynomial& operator = (const Polynomial &other);
	bool operator ==(const Polynomial & other);
	bool operator !=(const Polynomial & other);
	double ValueAtPoint(const double point);
	void Derivative();
};