#include<iostream>

using namespace std;

int main(){

    int t,x,y,k;

    cin>>t;
    while(t--){
        cin>>x>>y>>k;

        if(((x+y)/k)%2 == 0){
            cout<<"Chef"<<endl;
        }
        else{
            cout<<"Paja"<<endl;
        }
    }
    return 0;
}
