#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float principal, time, rate, emi;
	cout << "Enter principal amount, rate and time " << endl;
	cin >> principal >> rate >> time;
	rate = rate / (12 * 100);
	time = time * 12;
	emi =  (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
	cout << "EMI = " << emi << endl;

	return 0;
	
}
