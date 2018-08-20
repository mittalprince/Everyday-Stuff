/*
Pangram Checking

Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.

Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’]
“The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contains all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

	string s = "hello check this sentence";

	vector<int>v(26);
	int k;

	for (int i=0;i<s.length();i++)
	{
		if(s[i]>='A' && s[i]<='Z'){
			 k = s[i] - 'A';
			v[k]= 1;
		}


	else if (s[i]>='a' && s[i]<='z'){
		 k = s[i] - 'a';
			v[k]= 1;
	}

	}


	if(find(v.begin(),v.end(),0)!= v.end() )
	{
		cout<<"false";
	}
	else
	{
		cout<<"true";
	}

	return 0;
}
