#include <iostream>
#include<vector>
#include<math.h>

using namespace std;

int main() {
    long long N;
    long long T;
    long long K;
    long long prev = 0;
    long long next;
    long long req,count;
    
    cin>>T;
    
    while(T--)
    {
        cin>>N;
        cin>>K;
        count = 0;
        prev = 0;
        while(N--)
        {
            cin>>next;
            
            
            req = next - prev;
            
            if(req <= K)
            {
                prev = next;
                continue;
            }
            else
            {
                req = ceil((float)req/K) - 1;
                
                count += req;
                
                prev = next;
            }
        }
        cout<<count<<endl;
    }
  return 0;
}