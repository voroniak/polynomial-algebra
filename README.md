## Polynomial algebra
# Description:
This class will help students  understand the basics of polynomial algebra and also provide good examples of operator overload, how they can be used in OOP and how to handle dynamic memory when creating classes.
# Class possibilities:
  - addition of polynomials;
  - subtraction of polynomials;
  - multiplication of polynomials;
  - equality test;
  - the value at the point;
  - derivative;
  # Methods
 
  |  Method | Description |
  |---------|:-----------:|
  | double ValueAtPoint(const double point) |returns the polynomial value at a point|
  | void Derivative() |find the derivative of the polynomial by changing it|
  |int GetMaxDegree()const| returns max degree of polynomial |
  |void SetMaxDegree(int _maxDegree) | change max degree of polynomial and equation to zero all coefficients |
 | void SetCoefficients(istream & is) | change coefficients |
 | void GetCoefficients(ostream & os)const | write a polynomial using a stream ostream |
 |Polynomial operator + (const Polynomial &other) | adds two polynomials |
 | Polynomial operator - (const Polynomial &other) | subtracts two polynomials |
 | Polynomial operator * (const Polynomial &other) | multiply two polynomials |
 | Polynomial& operator = (const Polynomial &other) | copying polynomial |
 | bool operator ==(const Polynomial & other) | check of two polynomials for equality |
 | bool operator !=(const Polynomial & other) | check of two polynomials for inequality |
 
