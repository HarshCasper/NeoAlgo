#include <iostream> //header files
using namespace std;

int main() //main function
{
    int nthterm, iteration, firstterm = 2, secondterm = 1, totalofterms;
	cout << "Enter the number of terms desired in the lucas series: ";
	cin >> nthterm;
	
	if (nthterm == 1)   //checking if series is upto one term
		cout << endl << 2 << endl;
	else if (nthterm == 2)   //checking if series is upto two terms
		cout << endl << 2 << endl << 1 << endl;
	else if (nthterm > 2)
	{
		cout <<endl<<"Lucas series for "<< nthterm<< " terms is:"<<endl<< firstterm << endl << secondterm << endl;
		for (iteration = 0; iteration < nthterm-2; iteration++)
		{
			totalofterms = firstterm + secondterm;//calulating the sum
			cout << totalofterms << endl;//displaying the sum
			firstterm = secondterm;
			secondterm = totalofterms;

		}
	}
		//Note: Lucas series is not the same as the fibonnaci series. lucas and fibonacci series are complimentary to each other.
	return 0;
}