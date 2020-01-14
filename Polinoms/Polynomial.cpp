#include "Polynomial.h"

Polynomial::Polynomial() :maxDegree(1)
{
	coefficients = new double[maxDegree];
	coefficients[0] = 0;
}

Polynomial::Polynomial(int _maxDegree) :maxDegree(_maxDegree)
{
	coefficients = new double[maxDegree+1];
	for(int i =0; i<= maxDegree; i++)
	{
		coefficients[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial & other)
{
	if(coefficients!=nullptr)
	{
		delete[]coefficients;
	}
	coefficients = new double[other.maxDegree];
	maxDegree = other.maxDegree;
	
	for(int i =0 ; i<=maxDegree; i++)
	{
		coefficients[i] = other.coefficients[i];
	}
}

Polynomial::~Polynomial()
{
	delete[]coefficients;
}

void Polynomial::SetMaxDegree(int maxDegree)
{
	if(coefficients!=nullptr)
	{
		delete[]coefficients;
	}
	this->maxDegree = maxDegree;
	coefficients = new double[this->maxDegree+1];
	for (int i = 0; i <= maxDegree; i++)
	{
		coefficients[i] = 1;
	}
}

Polynomial Polynomial::operator+(const Polynomial & other)
{

	if (this->maxDegree >= other.maxDegree)
	{
		Polynomial res(this->maxDegree);
		for (int i = 0; i <= other.maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i] + other.coefficients[i];
		}
		for (int i = other.maxDegree+1; i <= this->maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i];
		
		}
		return res;
	}
	else
	{
		Polynomial res(other.maxDegree);
		for (int i = 0; i <= this->maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i] + other.coefficients[i];
		}
		for (int i = this->maxDegree + 1; i <= other.maxDegree; i++)
		{
			res.coefficients[i] = other.coefficients[i];
			
		}
		return res;
	}
}

Polynomial Polynomial::operator-(const Polynomial & other)
{
	if (this->maxDegree >= other.maxDegree)
	{
		Polynomial res(this->maxDegree);
		for (int i = 0; i <= other.maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i] - other.coefficients[i];
		}
		for (int i = other.maxDegree + 1; i <= this->maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i];

		}
		return res;
	}
	else
	{
		Polynomial res(other.maxDegree);
		for (int i = 0; i <= this->maxDegree; i++)
		{
			res.coefficients[i] = this->coefficients[i] - other.coefficients[i];
		}
		for (int i = this->maxDegree + 1; i <= other.maxDegree; i++)
		{
			res.coefficients[i] = -other.coefficients[i];

		}
		return res;
	}
}

Polynomial Polynomial::operator*(const Polynomial & other)
{
	Polynomial res (maxDegree + other.maxDegree);
	
	for(int i = 0; i <= maxDegree; i++)
	{
		for (int j = 0; j <= other.maxDegree; j++)
		{
			res.coefficients[i + j] += (coefficients[i] * other.coefficients[j]);
		}
	}

	
	return res;
}

Polynomial& Polynomial::operator=(const Polynomial & other)
{
	if(coefficients!=nullptr)
	{
		delete[]coefficients;
	}
	this->maxDegree = other.maxDegree;
	coefficients = new double[maxDegree+1];
	for(int i=0; i <= maxDegree; i++)
	{
		coefficients[i] = other.coefficients[i];
	}
	return *this;
}

Polynomial operator*(Polynomial &ob, double multiplier)
{
	
	for(int i=0; i <= ob.maxDegree; i++)
	{
		ob.coefficients[i] = ob.coefficients[i]* multiplier;
	}
	return ob;
}

void Polynomial::SetCoefficients(istream & is)
{
	for(int i =0 ; i <= maxDegree; i++)
	{
		cout << "input coefficient x^(" << i << ") :" << endl;
		is >> coefficients[i];
	}
}

void Polynomial::GetCoefficients(ostream & os)
{
	for (int i = 0; i <= maxDegree; i++)
	{
		if(coefficients[i]<0)
		{
			cout << "(";
			os << coefficients[i];
			cout << ") x^(" << i << ") ";
		}
		else if (coefficients[i] == 0)
		{
			continue;
		}
		else
		{
			os << coefficients[i];
			cout << " x^(" << i << ") ";
		}
		if (i != maxDegree)
		{
			cout << "+ ";
		}
	}
}

bool Polynomial::operator==(const Polynomial & other)
{
	if(this->maxDegree!=other.maxDegree)
	{
		return false;
	}
	else
	{
		for(int i =0; i<this->maxDegree; i++)
		{
			if(this->coefficients[i]!=other.coefficients[i])
			{
				return  false;
			}
		}
		return  true;
	}
	
}

bool Polynomial::operator!=(const Polynomial & other)
{
	for (int i = 0; i < this->maxDegree; i++)
	{
		if (this->coefficients[i] == other.coefficients[i])
		{
			return  false;
		}
	}
	return  true;
}

double Polynomial::ValueAtPoint(const double point)
{
	double res = 0;
	for(int i =0; i <= maxDegree; i++)
	{
		res += (coefficients[i] * pow(point, i));
	}
	return res;
}

void Polynomial::Derivative()
{
	for(int i =0 ; i<=maxDegree; i++)
	{
		coefficients[i] *= i;
	}
	for(int i =0; i  < maxDegree; i++)
	{
		coefficients[i] = coefficients[i + 1];
	}
	maxDegree --;
}

int Polynomial::GetMaxDegree()const
{
	return maxDegree;
}
