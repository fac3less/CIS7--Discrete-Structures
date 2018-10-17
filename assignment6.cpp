#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <regex>

typedef unsigned long int ulint;

using namespace std;
using namespace std::chrono;

void getValues();
int GCD(int input, int input2);

int main()
{
	string input1;
	string input2;

	int number1 = 0;
	int number2 = 0;
	char answer;

	 regex rx("[1-9][0-9]*");

	   cout << "Greatest Common Divisor Calculator." << endl;
    do
    {
        cout << "Enter Two Positive Integers: " << endl;

        do
        {
        cout << "input 1: ";
        cin >> input1;

        } while (!regex_match(input1,rx));

        do
        {
        cout << "input 2: ";
        cin >> input2;

        } 
        while (!regex_match(input2,rx));

        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

        int gcd = GCD(number1 =stoi(input1), number1 = stoi(input2));

        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
        auto nanduration = chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();

        cout << "GCD of " << input1 << " and " << input2 << " is " << gcd << "." << endl;
        cout << "Duration: " << duration << " microseconds. (" << nanduration << " nanoseconds)" << endl;
        cout << "Enter another set of values? (Y/N) " << endl;
        cin >> answer;

    } while (toupper(answer) == 'Y');
    return 0;

}

int GCD(int number1, int number2)
{
        if (number1 == 0)
        {
            return number2;
        }
return GCD(number2 % number1, number1);
}
