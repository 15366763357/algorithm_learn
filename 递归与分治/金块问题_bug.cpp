#include<bits/stdc++.h>
using namespace std;
void maxmin(int a[],int i,int j,double &fmax,double &fmin)
{
	int mid;double lmax,lmin,rmax,rmin;
	if(i==j){
		fmax=a[i];
		fmin=a[i];
	}
	else if(i=j-1)
	{
		if(a[i]<a[j]){
			fmax=a[j];
			fmin=a[i];
		}
		else{
			fmax=a[i];
			fmin=a[j];
		}
	 }
	 else{
	 	mid=(i+j)/2;
	 	maxmin(a,i,mid,lmax,lmin);
	 	maxmin(a,mid+1,j,rmax,rmin);
	 	fmax=max(lmax,rmax);
	 	fmin=min(lmin,rmin);
	 } 
}
int main()
{
	double fmax,fmin;
	int a[5]={0,20,3,2,5};
	maxmin(a,0,4,fmax,fmin);
	cout<<fmax<<' '<<fmin<<endl;
	return 0;
 } 
