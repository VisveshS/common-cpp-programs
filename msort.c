#include<bits/stdc++.h> 
#define N 100001
using namespace std;
void merge(int A[N],int a,int B[N],int b,int C[N])
{
	int i=0,j=0,k=0;
	while(i<a&&j<b)
		C[k++]=A[i]>B[j]?B[j++]:A[i++];
	while(i<a)
		C[k++]=A[i++];
	while(j<b)
		C[k++]=B[j++];
}
int msort(int A[N],int n)
{
	if(n<=1)return 0;
	int L[N],l=n/2,R[N],r=n-n/2,i;
	for(i=0;i<l;i++)
		L[i]=A[i];
	for(i=l;i<n;i++)
		R[i-l]=A[i];
	msort(L,l);
	msort(R,r);
	merge(L,l,R,r,A);
	return 0;
}
int main()
{
	return 0;
}