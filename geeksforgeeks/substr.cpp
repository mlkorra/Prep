


/* Usage of Substring in Cpp*/


#include <bits/stdc++.h>
using namespace std;


int main()
{
	string str = "We think in generalities,but we live in details";

	string str2 = str.substr(0);

	//size_t : Unsigned integral type
	//find   : locates the position of live
	size_t pos = str.find("live"); 

	//substr : returns substring with given positions
	string str3 = str.substr(pos);

	cout << str2 << ' ' << str3 << '\n';

	return 0;
}