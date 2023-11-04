#include<iostream>
using namespace std;

int output[1000]={0};     //將此陣列裡所有的成員預設值為0
int Fibonacci(int n)
{
	int result=output[n];
	if(result==0)
	{
		if(n==0)
		  return 0;
		if(n==1)
		{
		  output[n]=1;
		  return 1;
		}
	        output[n]=Fibonacci(n-1)+Fibonacci(n-2);
	        return output[n];
	}
	else
		return result;
}

int main()
{
	for(int i=0;i<=10;i++)
	{
	        cout<<Fibonacci(i)<<"  ";
	}
	cout<<endl;
	for(int i=0;i<=10;i++)
	{
		cout<<output[i]<<"  ";
	}
}
