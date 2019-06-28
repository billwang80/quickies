#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

// the value entered for divisor should be same for value of num
bool isPrime(int num, int divisor)
{
    if(num == 2)
        return true;
    if(divisor-1 == 1)
        return true;
    if(num % (divisor-1) != 0)
    {
        isPrime(num, divisor - 1);
    }
    else
        return false;
}

int main()
{
    cout << isPrime(51, 51) << endl; // not prime
    cout << isPrime(91, 91) << endl; // not prime
    cout << isPrime(103, 103) << endl; // prime
    cout << isPrime(2, 2) << endl; // prime
    cout << isPrime(13, 13) << endl; // prime
    cout << isPrime(61, 61) << endl; // prime
    cout << isPrime(6, 6) << endl; // not prime
    cout << isPrime(668, 668) << endl; // not prime
    cout << isPrime(69, 69) << endl; // not prime
}
/*
0
0
1
1
1
1
0
0
0

Process returned 0 (0x0)   execution time : 0.439 s
Press any key to continue.
*/
