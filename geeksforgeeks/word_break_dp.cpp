#include <iostream>
#include <string.h>
using namespace std;

bool searchDict(string s)
{
	string dictionary[] = {"rahul","dev","taja","love","romoe","neural","networks","intelligence","deep","learning"};

	int i,size;
	size = sizeof(dictionary)/sizeof(dictionary[0]);
	for(i=0;i<size;i++){
		if(dictionary[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

bool wordbreak(string s)
{

	int size = s.size();

	/*Corner Case*/
	if(size == 0){
		return true;
	}

	/* Used for storing if a string[0:i-i] is in the dictionary or not*/
	bool check[size+1];
	memset(check,0,sizeof(check));

	for(int i=1;i<=size;i++)
	{

		//Tricky part here is that substr(0,i) : has length i-1
		if(check[i] == false && searchDict(s.substr(0,i))){
			check[i] = true;
		}

		if(check[i] == true){

			if(i == size){
				return true;
			}

			for(int j=i+1;j<=size;j++){

				if(check[j] == false && searchDict(s.substr(i,j-i))){
					check[j] = true;
				}

				if(j== size && check[j] == true){
					return true;
				}

			}	
		}


	}

	return false;

}


int main()
{

	string s;
	cout << "Enter string" << endl;
	cin >> s;

	if(wordbreak(s)){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}