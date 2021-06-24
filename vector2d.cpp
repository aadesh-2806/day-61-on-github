#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int> > a;			int i,j,n,m,t;
	cout<<"enter no's ";
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		vector<int> b;
		for(j=0;j<m;j++)
		{
			cout<<"enter value"<<i+1<<j+1<<"=";
			cin>>t;
			b.push_back(t);
		}
		a.push_back(b);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
				cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
