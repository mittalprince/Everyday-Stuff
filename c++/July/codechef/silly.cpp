#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int t,n;
    cin>>t;

    while(t--){
        long long sum = 0;
        int even1, even2;
        even1 = 0;
        even2 = 0;
        cin>>n;
        for(int i=0; i<n; i++){
            long long x;
            cin>>x;
            sum += x;
            if(x%2 == 0){
                even1++;
            }
        }
        for(int i=0; i<n; i++){
            long long x;
            cin>>x;
            sum += x;
            if(x%2 == 0){
                even2++;
            }
        }
        sum = sum - (abs(even1-even2));
        cout<<sum/2<<endl;
    }
}