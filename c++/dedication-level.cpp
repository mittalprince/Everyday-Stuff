/* Problem statement link https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/baaki-che/  */

    #include<iostream>
    #include<vector>
    #include<utility>
    #include<algorithm>
     
    using namespace std;
     
    bool sort_sec(const pair<string, int>& a, const pair<string, int>& b){
        
        return (a.second > b.second);
    }
     
    int main(){
        
        int n,hours;
        string name;
        vector<pair <string, int> > v;
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin>>name>>hours;
            v.push_back(make_pair(name, hours));
        }
        
        sort(v.begin(), v.end(), sort_sec);
        
        for(int i=0;i<3;i++){
            cout<<v[i].first<<endl;
        }
        
        return 0;
    }
