#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void prince(vector<int> &v){
  int temp;
  if(v[1]>v[0]){
    temp=v[1];
    v[1]=v[0];
    v[0]=temp;
  }
  vector<int>::iterator i;
  for(i=v.begin();i<v.end();i++){
    if(*i< *(i+1)){
      temp=*i;
      *(i+1)=*i;
      *i=temp;
    }
    i++;
    if(i==(v.end()-1))
    return ;

    if(*i > *(i+1)){
      temp=*i;
      *(i+1)=*i;
      *i=temp;
    }
  }
}

int main(){

  vector<int> v{3,6,7,10,20,7};

  prince(v);

  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;

  return 0;
}
