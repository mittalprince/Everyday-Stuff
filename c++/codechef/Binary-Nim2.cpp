#include<bits/stdc++.h>

using namespace std;

void f(string str){
	int count =0,zero=0;
	for(unsigned int i=0; i<str.length(); i++){
		if(str[i] == '1'){
			unsigned int j = i;
			while(j < str.length() && str[j] == str[j+1]){
				j++;
			}
			i=j;
			count++;
		}
		else if(str[i] == '0') {
			unsigned int j= i;
			while(j <str.length() && str[j] == str[j+1])
				j++;

			i=j;
			zero++;	
		}
	}

	cout<<count<<" "<<zero<<endl;
}

int main(){
	string str;
	cin>>str;

	f(str);
	return 0;
}