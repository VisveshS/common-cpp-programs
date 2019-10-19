#include<bits/stdc++.h>
#include<iostream>
#define N 100001
#define LL long long int
using namespace std;
LL GCD(LL a,LL b)
{
	LL t;
	if(b>a)
	{
		t=a;
		a=b;
		b=t;
	}
	if(b==0)
		return a;
	return(GCD(b,a%b));
}
int main()
{
	LL a,b;
	cin>>a>>b;
	cout<<GCD(a,b)<<endl;
	return 0;
}