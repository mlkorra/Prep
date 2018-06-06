/*

Work BreaK Problem : Here we are given a dictionary of words,and an input string is given

We have return TRUE if the given string can be splitted in to words.which are in the dictionary
else return FALSE


We are using RECURSION here,to solve
In the next session,we see DYNAMIC PROGRAMMING

*/


#include <iostream>
#include <string.h>

using namespace std;

bool searchdict(string s)
{
	string dictionary[] = {"rahul","dev","taja","love","romoe","neural","networks","intelligence","deep","learning"};

	int i;
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for(int i=0;i<size;i++){
		if(dictionary[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

bool wordBreak(string s)
{	
	int i,sz;
	sz = s.size();	

	// Corner Case
	if(sz == 0){
		return true;
	}

	for(i=1;i<=sz;i++){
		if(searchdict(s.substr(0,i)) && wordBreak(s.substr(i,sz-i))){
			return true;
		}
	}

	return false;
}

int main()
{

	string s;
	cout << "Enter string " << endl;
	cin>>s;

	if(wordBreak(s)) {
		cout << "YEs" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}