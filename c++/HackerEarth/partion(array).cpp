/*Three way partitioning of an array around a given range
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int low,high,n;
    cin>>n;

    vector<int>v(n);

    for(auto& i: v){
        cin>>i;
    }

    cin>>low>>high;
    int begin = 0;
    int last = n-1;

  for(int i=0;i<=last;i++){

      if(v[i]<low){
          swap(v[i],v[begin]);
          begin++;
      }

      else if(v[i]>high){
          swap(v[i],v[last]);
          last--;
          i--;
      }

  }

    for(auto i: v){
        cout<<i<<" ";
    }




	return 0;
}
