#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> v(n);

  for(int i=0;i<v.size();i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for(int j=0;j<v.size();j++){
    cout<<v[j]<<" ";
  }

  cout<<endl;
  return 0;
}
