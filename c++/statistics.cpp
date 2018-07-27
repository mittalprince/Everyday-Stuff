/* Problem statement link https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/statistics-2/  */

#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    
    long long n, max=0;
    string name, sports, ans;
    unordered_map<string, string> m;
    unordered_map<string, int> m1;
    cin>>n;
    while(n--){
        cin>>name>>sports;
        
        if(m.find(name) == m.end()){
            
            m[name] = sports;
            
            if(m1.find(sports) != m1.end())
                m1[sports]++;
            else m1[sports] = 1;
            
            if(max < m1[sports]){
                ans = sports;
                max = m1[sports];
            }
            else if(max == m1[sports]){
                if(ans > sports)
                    ans = sports;
            }
        }
    }
    
    cout<<ans<<endl;
    cout<<m1["football"];
    
    
    return 0;
}