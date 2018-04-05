#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

void prince(vector <int> &v){
  vector<int>::iterator i1,i2;
  i1 = v.begin();
  i2 = (v.end()-1);

  while(i1<i2){
    while(*i1 % 2 != 0){
      ++i1;
    }
    while((*i2 % 2 == 0)){
      --i2;
    }
    if(!(i1<i2))
      return;
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
    ++i1;--i2;
  }
}

int main(){
  int n = 5;
  vector<int> v{2,3,4,5,6,9};

  prince(v);
  for(int j=0;j<n;j++){
    cout<<v[j]<<" ";
  }
  cout<<endl;
  return 0;
}
