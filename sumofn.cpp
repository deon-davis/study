#include<iostream>
#include<vector>

using namespace std;

const int N = 40;
inline void sum(int& p, int n,vector<int> d)
{
	int i;
	p = 0;
	for(int i = 0;i<n;++i)
		p = p+d[i];
}

int main()
{
	int i;
	int accu = 0;
	vector<int> data;
	for(i =0;i<N;++i)
		data.push_back(i);
	sum(accu,N,data);
	cout<<"sum is"<<accu<<endl;
	return 0;
}


