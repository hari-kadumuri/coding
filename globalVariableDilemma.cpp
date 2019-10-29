#include <iostream>
using namespace std;

int a = 10;

int main(int argc, char const *argv[])
{
	int a = 5;
	cout<<"hello world\n"<<::a+5<<endl;
	cout<<"hello world\n"<<a+5<<endl;
	return 0;
}