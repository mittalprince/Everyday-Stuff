/* Problem statement link  https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/biased-chandan/ */

#include <iostream>
#include <stack>

using namespace std;
 
int main() {
	long long N,sum=0;
	int temp;
    stack < int > s;
    cin>>N;
    while(N--){
        cin>>temp;
        if(temp==0&&(!s.empty())){
            sum -= s.top();
            s.pop();
	    }
	    else{
        sum += temp;
        s.push(temp);
        }
    }
	cout<<sum<<endl;
    	
	return 0;
}

