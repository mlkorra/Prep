/*
Balanced Paranthesis
*/

#include <bits/stdc++.h>
using namespace std;

bool ParanthesisChecker(string str)
{
	int i;
	stack<int> s;
	for(i=0;i<str.length();i++){
		if(str[i]=='['||str[i]=='{'||str[i]=='('){
			s.push(str[i]);
			continue;
		}

		if(s.empty()) return false;
		char x;

		switch(str[i])
		{
			case ']':
				x = s.top();
				s.pop();
				if(x=='{'||x=='(') return false;
				break;

			case '}':
				x = s.top();
				s.pop();
				if(x=='['||x=='(') return false;
				break;

			case ')':
				x = s.top();	
				s.pop();
				if(x=='['||x=='{') return false;
				break;
		}
	}

	return s.empty();
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		if(!ParanthesisChecker(s)) cout << "not balanced" << endl;
		else cout << "balanced" << endl;
	}
	return 0;
}