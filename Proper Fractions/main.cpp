#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

class Fraction
{
    private:
        int numerator;
        int denominator;

    public:
        Fraction()
        {
            numerator = 0;
            denominator = 1;
        }

        Fraction(int num0, int den0)
        {
            if(fabs(den0) >= fabs(num0))
            {
                numerator = num0;
                denominator = den0;
            }
            else
            {
                numerator = 0;
                denominator = 1;
            }
        }

        void set_frac(int num0, int den0)
        {
            if(fabs(den0) >= fabs(num0))
            {
                numerator = num0;
                denominator = den0;
            }
            else
            {
                numerator = 0;
                denominator = 1;
            }
        }

        void set_numerator(int num0)
        {
                numerator = num0;
        }

        void set_denominator(int den0)
        {
                denominator = den0;
        }

        int get_numerator() const
        {
            return numerator;
        }

        int get_denominator() const
        {
            return denominator;
        }

        double returnDecimal(int decimalPlaces)
        {
            double decimal = (double) numerator * pow(10, decimalPlaces)/denominator;
            decimal = round(decimal);
            decimal = decimal / pow(10, decimalPlaces);
            return decimal;
        }

        bool isExactlySame(Fraction const & other) const
        {
            double multiple = (double) numerator / other.get_numerator();
            if(denominator == other.get_denominator() * multiple)
                return true;
            return false;
        }

        void output()
        {
            cout << "Fraction: " << get_numerator() << " / " << get_denominator() << endl;
        }
};

int main()
{
    Fraction f0(2, 9);
    cout << f0.returnDecimal(3) << endl;
    cout << f0.returnDecimal(4) << endl;
    f0.output();
    Fraction f1 = Fraction();
    f1.set_numerator(5);
    f1.set_denominator(10);
    Fraction f2 = Fraction();
    f2.set_frac(2,4);
    cout << "f1 numerator: " << f1.get_numerator() << endl;
    cout << "f2 denominator: " << f2.get_denominator() << endl;
    cout << "f1 and f2 are equal: " << f1.isExactlySame(f2) << endl;
    cout << "f0 and f2 are equal: " << f0.isExactlySame(f2) << endl;
}
/*
0.222
0.2222
Fraction: 2 / 9
f1 numerator: 5
f2 denominator: 4
f1 and f2 are equal: 1
f0 and f2 are equal: 0

Process returned 0 (0x0)   execution time : 0.275 s
Press any key to continue.
*/
