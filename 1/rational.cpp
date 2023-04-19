#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int gcd(int num1, int num2)
{
    num1 = abs(num1);
    num2 = abs(num2);

    int gcd = 1;
    int min = (num1 < num2) ? num1 : num2;
    for (int i = 1; i <= min; i++)
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    
    return gcd;
}

class Rational
{
    public:
        int numerator;
        int denominator;
        Rational()
        {
            numerator = 0;
            denominator = 1;
        }
        Rational(int numerator_, int denominator_)
        {
            numerator = numerator_;
            denominator = denominator_;

            if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            if (denominator == 0)
            {
                throw exception();
            }

            int nod = gcd(numerator, denominator);
            if (nod != 1)
            {
                numerator /= nod;
                denominator /= nod;
            }
        }
        Rational operator=(Rational num)
        {
            numerator = num.numerator;
            denominator = num.denominator;

            return *this;
        }
        Rational& operator++() // prefix
        {
            numerator += denominator;
            return *this;
        }
        Rational operator++(int) // postfix
        {
            Rational temp = *this;
            ++*this;
            return temp;
        }
};

Rational cut(Rational num)
{
    int nod = gcd(num.numerator, num.denominator);
    if (nod != 1)
    {
        num.numerator /= nod;
        num.denominator /= nod;
    }

    return num;
}

ostream& operator<<(ostream& os, Rational num)
{
    if (num.numerator == 0 || num.denominator == 1)
        os << num.numerator << endl;
    else
        os << num.numerator << '/' << num.denominator << endl;

    return os;
}

istream& operator>>(istream& is, Rational& num)
{
    is >> num.numerator;
    is >> num.denominator;

    return is;
}

bool operator<(Rational num1, Rational num2)
{
    int denominator1 = num1.denominator;
    int denominator2 = num2.denominator;

    num1.numerator *= denominator2;
    num1.denominator *= denominator2;

    num2.numerator *= denominator1;
    num2.denominator *= denominator1;

    return (num1.numerator < num2.numerator) ? true : false;
}

bool operator>(Rational num1, Rational num2)
{
    int denominator1 = num1.denominator;
    int denominator2 = num2.denominator;

    num1.numerator *= denominator2;
    num1.denominator *= denominator2;

    num2.numerator *= denominator1;
    num2.denominator *= denominator1;

    return (num1.numerator > num2.numerator) ? true : false;
}

bool operator==(Rational num1, Rational num2)
{
    return (num1.numerator == num2.numerator && num1.denominator == num2.denominator) ? true : false;
}

Rational operator*(Rational num1, Rational num2)
{
    num1.numerator *= num2.numerator;
    num1.denominator *= num2.denominator;

    return cut(num1);
}

Rational operator/(Rational num1, Rational num2)
{
    if (num2.numerator == 0)
        throw exception();

    num1.numerator *= num2.denominator;
    num1.denominator *= num2.numerator;

    return cut(num1);
}

Rational operator+(Rational num1, Rational num2)
{
    int denominator1 = num1.denominator;
    int denominator2 = num2.denominator;

    num1.numerator *= denominator2;
    num1.denominator *= denominator2;

    num2.numerator *= denominator1;
    num2.denominator *= denominator1;

    num1.numerator += num2.numerator;

    return cut(num1);
}

Rational operator-(Rational num1, Rational num2)
{
    int denominator1 = num1.denominator;
    int denominator2 = num2.denominator;

    num1.numerator *= denominator2;
    num1.denominator *= denominator2;

    num2.numerator *= denominator1;
    num2.denominator *= denominator1;

    num1.numerator -= num2.numerator;

    return cut(num1);
}

int main()
{
    Rational num;
    cin >> num;

    cout << num;

    return 0;
}
