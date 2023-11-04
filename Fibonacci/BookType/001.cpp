#include<iostream>
using namespace std;

int output[1000]={0};

int fib(int n)
{
	int result=output[n];
	if(result==0)
	{
		if(n==0)
		  return 0;
		if(n==1)
		  return 1;
		else
                  return (fib(n-1)+fib(n-2));
		output[n]=result;
	}
	return result;
}

int main()
{
	for(int i=0;i<=10;i++)
	{
		cout<<fib(i)<<"  ";
	}
	cout<<endl;
	for(int i=0;i<=10;i++)
	{
		cout<<output[i]<<"  ";
	}
	cout<<endl;
}

