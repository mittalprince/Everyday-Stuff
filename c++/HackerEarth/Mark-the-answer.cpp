   /* Problem statement https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/mark-the-answer-1/ */

    #include<iostream>
     
    using namespace std;
     
    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long N,X,marks=0, skip=0,n;
        
        cin>>N>>X;
        
        while(N--){
            
            cin>>n;
            if(skip <= 1){
                
                if(n <= X)
                    marks++;
                
                else skip++;
            }
        }
        cout<<marks<<endl;
        
        return 0;
    }