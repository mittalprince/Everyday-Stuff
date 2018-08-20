#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
     
using namespace std;
     
typedef unsigned long long ll ;
typedef pair<long long, long long> p;
     
struct node{
	p data;
	vector<ll> v;
	ll height = 0;
	node *left =  nullptr;
	node *right = nullptr;
};
     
node* newNode(p data){
	node *temp = new node;
	temp->data.first = data.first;
	temp->data.second = data.second;
     
	return temp;
}
     
ll height( node *root){
	if(root == nullptr)
		return 0;
 
   	return root->height;
}
     
ll get_balance_factor(node *root){
     
	if(root == nullptr)
		return 0;
 
	return height(root->left) - height(root->right);
}
    
node* right_rotate(node *z){
     
	node *y = z->left;
	node *t2 = y->right;
     
   	y->right = z;
   	z->left = t2;
     
   	z->height = max((height(z->left)), (height(z->right))) + 1;
   	y->height = max((height(y->left)), (height(y->right))) + 1;
     
   	return y;
}
     
node *left_rotate(node *z){
     
   	node *y = z->right;
   	node *t2 = y->left;
     
   	y->left = z;
   	z->right = t2;
     
   	z->height = max((height(z->left)), (height(z->right))) + 1;
   	y->height = max((height(y->left)), (height(y->right))) + 1;
     
   	return y;
}

node* insert(node* root, p data, ll diff){
     
   	if(root == nullptr){
   		node *temp = newNode(data);
   		temp->v.push_back(diff+1);
    
   		return temp;
   	}
     
   	if(root->data.first > data.first && root->data.second > data.first)
   		root->left = insert(root->left, data, diff);
     
   	else if(root->data.first < data.first && root->data.second < data.first)
   		root->right = insert(root->right, data, diff);
     
     
   	else{
    	p temp;
     
   		if(root->data.first < data.first){
    
   			if(root->data.second < data.second){
     
   				if(root->data.second == data.first){
     
   					temp.first = data.first+1;
   					temp.second = data.second;
     
    				// if(root->right)
    				// 		root->right->v.push_back(diff+1);
     
   					root->right = insert(root->right, temp, diff);
     
   					root->v.push_back(diff+1);
     
   				}
     
    			else{
    				temp.first = root->data.first;
    				temp.second = data.first - 1;
    					// if(root->left)
    					// 	root->left->v.push_back(diff+1);
     
    				root->left = insert(root->left, temp, diff);
     
    				temp.first = root->data.second+1;
    				temp.second = data.second;
     
    				// if(root->right)
   					// 	root->right->v.push_back(diff+1);
    
   					root->right = insert(root->right, temp, diff);
     
   					root->data.first = data.first;
   					root->v.push_back(diff+1);
   				}
   		
   			}
    
    		else if(root->data.second > data.second){
     
    			temp.first = root->data.first;
    			temp.second = data.first-1;
    			
    			// if(root->left)
    				// root->left->v.push_back(diff+1);
    
    			root->left = insert(root->left, temp, diff);
     
    			temp.first = data.second+1;
    			temp.second = root->data.second;
    				
   				// if(root->right)
   				// 	root->right->v.push_back(diff+1);
     
    			root->right = insert(root->right, temp, diff);
     
    			root->data.first = data.first;
    			root->data.second = data.second;
    			root->v.push_back(diff+1);
     
    		}
     
   			else {
    			temp.first = root->data.first;
    			temp.second = data.first - 1;
     
    			// if(root->left)
    			// 	root->left->v.push_back(diff+1);
     
    			root->left = insert(root->left, temp, diff);
     
    			root->data.first = data.first;
    			root->v.push_back(diff+1);
    		}
     
    	}
     
    	else if(root->data.first > data.first){
     
	    	if(root->data.second < data.second){
	     
   				if(root->data.first == data.second){
	     
	   					temp.first = data.first;
	   					temp.second = data.second-1;
	     
	   					// if(root->left)
	   					// 		root->left->v.push_back(diff+1);
	     
	   					root->left = insert(root->left, temp, diff);
	    
	   					root->v.push_back(diff+1);
	    
   				}
	    
   				else{
	    
	   					temp.first = data.first;
	   					temp.second = root->data.first-1;
	    
	   					// if(root->left)
	   					// 	root->left->v.push_back(diff+1);
	     
	   					root->left = insert(root->left, temp, diff);
	     
	    				temp.first = root->data.second+1;
	    				temp.second = data.second;
	     
	   					// if(root->right)
	   					// 	root->right->v.push_back(diff+1);
	    
	   					root->right = insert(root->right, temp, diff);
	     
	    				root->v.push_back(diff+1);
	    
   				}
   			}
	     
		   	else if(root->data.second > data.second){
		     
		   			temp.first = data.first;
		   			temp.second = root->data.first -1 ;
		     
		   			// if(root->left)
		   			// 	root->left->v.push_back(diff+1);
		   
		   			root->left = insert(root->left, temp, diff);
		   
		   			temp.first = data.second+1;
		   			temp.second = root->data.second;
		    
		   			// if(root->right)
		   			// 	root->right->v.push_back(diff+1);
		   
		   			root->right = insert(root->right, temp, diff);
		   
		   			root->data.second = data.second;
		   			root->v.push_back(diff+1);
	   
	   		}
	   
	   		else {
	   
	   			temp.first = data.first;
	   			temp.second= root->data.first-1;
	   
	   			// if(root->left)
	   			// 	root->left->v.push_back(diff+1);
	   
	   			root->left = insert(root->left, temp, diff);
	   
	   			root->v.push_back(diff+1);
	    
	   			}
	   	}
   
   		else if(root->data.first == data.first){
     
   			if(root->data.second < data.second){
   				temp.first = root->data.second+1;
   				temp.second = data.second;
    
   				// if(root->right)
   				// 	root->right->v.push_back(diff+1);
    
   				root->right = insert(root->right, temp, diff);
    
   				root->v.push_back(diff+1);
    
   			}
    
   			else {
   				temp.first = data.second+1;
   				temp.second = root->data.second;
    
   				// if(root->right)
   				// 	root->right->v.push_back(diff+1);
    
   				root->right = insert(root->right, temp, diff);
     
   				root->data.second = data.second;
    
   				root->v.push_back(diff+1);
   				
   			}
   		}
     
    	else {
     
   			root->v.push_back(diff+1);
   			return root;
    	}
    
   	}
     
   	root->height = max(height(root->left), height(root->right)) + 1;
     
    int balance_factor = get_balance_factor(root);
    
    if(balance_factor > 1 && data < root->left->data)
    	return right_rotate(root);
    
    if(balance_factor > 1 && data > root->left->data){
    	root->left = left_rotate(root->left);
    	return right_rotate(root);
    }
     
   	if(balance_factor < -1 && data > root->right->data)
   		return left_rotate(root);
    
   	if(balance_factor < -1 && data < root->right->data){
   		root->right = right_rotate(root->right);
   		return left_rotate(root);
   	}
   	
   	return root;
}
    
ll find_kth_smallest(node *root, ll x, ll k){
    
   	if(root == nullptr)
   		return 1;
     
   	if(root->data.first > x && root->data.second > x){
  	    if(root->left)
   		return find_kth_smallest(root->left, x, k);
   	}
    
   	else if(root->data.first < x && root->data.second < x){
   	    if(root->right)
   		return find_kth_smallest(root->right, x, k);
   	}
    
   	else if(root->data.first <= x && root->data.second >= x){
   		sort(root->v.begin(), root->v.end());
  		if(root->v.size() > k-1)
   		return root->v.at(k-1);
   		else return 1;
   	}
}
    
   int main(){
    
   	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
     
   	ll n,l,r,q,x,k,diff;
   	cin>>n;
   	p temp;
  	node *root = nullptr;
   	while(n--){
   		cin>>l>>r;
   		temp.first = l;
   		temp.second = r;
   		diff = r-l;
   		root = insert(root, temp, diff);
   	}
    
   	cin>>q;
   	while(q--){
   		cin>>k>>x;
    
   		cout<<find_kth_smallest(root, x, k)<<endl;
   	}
    
   	return 0;
}