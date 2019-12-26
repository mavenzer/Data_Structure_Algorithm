#include<iostream>
using namespace std;
long long int power(int base, int exponent)
{
	long long int smallAnswer;

	//base case 
	if(exponent==0)
		 return 1;

    //recursive case
    smallAnswer = power(base,exponent/2);
    smallAnswer*=smallAnswer;
    //If the exponent is of odd power
    if(exponent&1)
    	smallAnswer*=base;

    return smallAnswer;


}
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int base,exponent;
		cin>>base>>exponent;
		cout<<power(base,exponent)<<endl;
	}


	return 0;
}