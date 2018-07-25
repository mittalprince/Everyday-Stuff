/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/x-4/  */
#include <iostream>
#include <unordered_map>
using namespace std;
 
int main() {
    long long T,temp,max1=0,max2=0;
    
    long long N;
    cin>>T;
    
    while(T--){   
        unordered_map < long long,long long > m1, m2;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>temp;
            m1[temp]++;
            if(m1[temp]>m1[max1]){   
              max1 = temp;
            }
            else if(m1[temp]==m1[max1]&&temp>max1){
               max1 = temp;
            }
        }
        for(int i=0;i<N;i++){
           cin>>temp;
           m2[temp]++;
           if(m2[temp]>m2[max2]){   
               max2 = temp;
           }
           else if(m2[temp]==m2[max2]&&temp>max2){
               max2 = temp;
           }
       }
        if(max1>max2){
           cout<<"Rupam"<<endl;
         }
        else if(max1==max2){
           cout<<"Tie"<<endl;
         }
         else cout<<"Ankit"<<endl;
            
}
        
        return 0;
}

