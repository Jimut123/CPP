// templateFunc
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>	// can also use class instead of typename
T func_dec(T a, T b)
{
	return a+b;
} 
int main()
{
	int a=5,b=6;
	float a1=4.0,b1=3.0;
	cout<<"Int => "<<func_dec<int>(a,b)<<endl;
	cout<<" Float => "<<func_dec(a1,b1)<<endl;
	printf("%0.5f ",func_dec<float>(a1,b1));
	return 0;
}
