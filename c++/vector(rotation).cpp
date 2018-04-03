#include<iostream>
#include<vector>

using namespace std;

void clockrotate(vector <int> v, int d, int n){
    int i;
    vector <int> temp(n);
    for(i=0;i<d;i++){
      temp[i]=v[i];
    }
    for(i=d;i<n;i++){
      v[i-d]=v[i];
    }
    for(i=0;i<d;i++){
      v[(n-d)+i]=temp[i];
    }
    for(i=0;i<v.size();i++){
      cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
  int n,d;
  cin>>n>>d;
  d= d%n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  clockrotate(v,d,n);

  return 0;
}
