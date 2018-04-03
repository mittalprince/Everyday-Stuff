#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,i;
  cin>>n;
  vector<int> v(n);
  for(i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int> v2(v.size());
  for(i=0;i<v.size();i++){
    cin>>v2[i];
  }
  if(v==v2){
    cout<<"Equal \n";
  }
  else{
    cout<<"Sorry enter equal values \n";
  }

  return 0;
}
