#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){

    int n,i;
    cin>>n;
    while(n--){
        string input;
        cin>>input;
        stack<char> s;
        for(i=0;i<input.length();i++){
            if(s.empty()){
                s.push(input[i]);
            }
            else{
            if(input[i]=='('||input[i]=='{'||input[i]=='['){
                s.push(input[i]);
            }
            else {
                if(input[i]==']'){
                    if(s.top()=='['){
                        s.pop();
                    }
                }
                if(input[i]=='}'){
                    if(s.top()=='{'){
                        s.pop();
                    }
                }
                if(input[i]==')'){
                    if(s.top()=='('){
                        s.pop();
                    }
                }
            }
        }

            }
        if(s.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

}
    return 0;
}
