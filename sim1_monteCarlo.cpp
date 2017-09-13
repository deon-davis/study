#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int sides = 6;
inline int r_sides() 
{
	return (rand() % sides + 1);
}

int main()
{
	const int n_dice = 2;
	srand(clock());
	cout<<"enter number of trails";
	int trails;
	cin>>trails;
	int* outcomes = new int[n_dice * sides + 1];
	for(int j = 0; j<trails; ++j)
		outcomes[(r_sides())+(r_sides())]++;
	cout<<endl<<"probability:";
	for(int j = 2; j < n_dice * sides +1;++j)
		cout<<"j="<<j<<"p="<<static_cast<double>(outcomes[j])/trails<<endl;
}


