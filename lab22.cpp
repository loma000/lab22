#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);

	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
	friend ostream &operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

ostream &operator<<(ostream &os, const ComplexNumber &comp)
{
	if (comp.real != 0)
	{
		os << comp.real;
	}

	if (comp.imag != 0)
	{
		if (comp.imag >= 0 && comp.real != 0)
			os << "+";

		os << comp.imag << "i";
	}
	else
	{
		if (comp.real == 0)
		{
			os << 0;
		}
	}

	return os;
}

ComplexNumber operator+(double s, const ComplexNumber &c)
{
	return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c)
{
	return ComplexNumber(s - c.real, -c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}
ComplexNumber operator*(double s, const ComplexNumber &c)
{
	return ComplexNumber(s * c.real, s * c.imag);
}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
	return bool(real == c.real && imag == c.imag) ? true : false;
}
bool operator==(double a, const ComplexNumber &c)
{
	return bool(a == c.real && a == c.imag) ? true : false;
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
	double denominator = c.real * c.real + c.imag * c.imag;
	return ComplexNumber((real * c.real + imag * c.imag) / denominator,
						 (imag * c.real - real * c.imag) / denominator);
}
ComplexNumber operator/(double s, const ComplexNumber &c)
{
	return ComplexNumber(s * c.real / (pow(c.real, 2) + pow(c.imag, 2)), -1 * s * c.imag / (pow(c.real, 2) + pow(c.imag, 2)));
}
double ComplexNumber ::abs() { return sqrt(pow(real, 2) + pow(imag, 2)); }
double ComplexNumber ::angle() { return atan2(imag, real) * 57.2957795; }

int main()
{
	ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a + 2.5 << "\n";
	cout << 2.5 + a << "\n";
	cout << a - 1.5 << "\n";
	cout << 1.5 - a << "\n";
	cout << b + ComplexNumber(0, 2.5) << "\n";
	cout << c - c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a + b) / c;
	ComplexNumber e = b / (a - c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c * 2 << "\n";
	cout << 0.5 * c << "\n";
	cout << 1 / c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).abs() << "\n";
	cout << ComplexNumber(-1, 1).abs() << "\n";
	cout << ComplexNumber(1.5, 2.4).abs() << "\n";
	cout << ComplexNumber(3, 4).abs() << "\n";
	cout << ComplexNumber(69, -9).abs() << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).angle() << "\n";
	cout << ComplexNumber(-1, 1).angle() << "\n";
	cout << ComplexNumber(-1, -1).angle() << "\n";
	cout << ComplexNumber(1, -1).angle() << "\n";
	cout << ComplexNumber(5, 2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
	cout << (ComplexNumber(1, 1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
