#include<iostream>
#include<stack>
using namespace std;

int M(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}


int main() {
    int n;
    stack<int> s;
    int max=0,ch,no,temp;
    while(n--){
        cin>>ch;
        if(ch==1){
            cin>>no;
            if(s.empty()){
                s.push(no);
            }
            else{
                temp =M(no,s.top());
                s.push(temp);
            }
        }
        else if(ch==2){
            if(!s.empty()){
                s.pop();
             }
        }
        else if(ch==3){
            cout<<s.top();
            cout<<endl;
        }
    }
    return 0;
}
