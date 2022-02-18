#include<bits/stdc++.h>
#define ll long long
using namespace std;
int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int n;
bool isyear(int x)
{
	if((x%4==0 && x%100!=0)||(x%400==0))
		return 1;
	else return 0;
}
bool isdate(int x)
{
	bool flag=0;
	int y=x/10000;
	int m=(x/100)%100;
	int d=x%100;
	if(y>0 && m>0 && m<=12)
	{
		if(d<month[isyear(y)][m])
			flag=1;
	}
	return flag;
}
bool ishui(int x)
{
	int t=x,r=0;
	while(x)
	{
		r=r*10+x%10;
		x/=10;
	}
	if(t==r)
	return 1;
	else return 0;
}
bool isab(int x)
{
	bool flag=0;
	int y=x/10000;
	int m=(x/100)%100;
	int d=x%100;
	int k=y/100;
	int n=y%100;
	if(k==n && m==d)
	{
		flag=1;
	}
	return flag;
}
int main()
{
	cin>>n;
	int t=n;
	int i=0,j=0;
	while(!i)
	{
		t++;
		if(isdate(t))
		{
			if(ishui(t))
			{
				i=t;
			}
		}
	}
	t=i-1;
	while(!j)
	{
		t++;
		if(isdate(t))
		{
			if(ishui(t))
			{
				if(isab(t))
				j=t;
			}
		}
	}
	cout<<i<<endl<<j<<endl;
	return 0;
}

