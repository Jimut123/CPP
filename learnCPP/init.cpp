#include <iostream>
#define lol 1000;
using namespace std;
int main()
{
	int x(8); // constructor initialization
	int y{9}; //uniform initilization
	cout<<"x = "<<x<<" y = "<<y<<endl;
	y = 2 + (x = 5);
	cout<<"y = "<<y<<endl;
	int a,b=1;
	a = (b=1, b+2,a+4);
	cout<<"a = "<<a<<endl;
	return 0;
}
