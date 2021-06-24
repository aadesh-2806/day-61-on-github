#include<iostream>
#include<vector>

using namespace std;


inline void sum(int &p,int n,vector<int>& d)
{
    int i;
    p=0;
    for(i=0; i<n; ++i)
	{
		p=p+d.at(i);
	}
}

int main()
{
    const int n=40;
    int i;
    int accum=0;
    vector<int> data(40);
    
    for(i=0; i<n; ++i)
    {
       	data.insert(data.begin(), i);
	}

    sum(accum, n, data);

    cout<<"sum is "<<accum<<endl;
}
