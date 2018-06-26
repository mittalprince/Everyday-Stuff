
#include<iostream>

using namespace std;

struct node{
  int data;
  node *left, *right;
};

struct node* newNode(){
  node* newnode = new node;
  //  newnode->data= key;
    newnode->left = nullptr;
    newnode->right = nullptr;

    return newnode;
}

void inorderTraversal(struct node* root){
      if(root==NULL)
        return;

      inorderTraversal(root->left);
      cout<<root->data<<endl;
      inorderTraversal(root->right);
  }

void insertion(struct node* root, string s ,int d){
  struct node* temp = root;
  for(int j=0;j<s.size();j++){
    if(s[j] == 'L'){
      if(temp->left == nullptr){
        temp->left = newNode();
      }
      temp = temp->left;}
    else if(s[j] == 'R') {
      if(temp->right == nullptr){
        temp->right= newNode();
      }
      temp = temp->right;
  }
}
//temp = newNode();
temp->data = d;
}

int maxdia(struct node* root, int& max){
  if(root == NULL){
    return 0;
  }
  else{
    int lheight = maxdia(root->left,max);
    int rheight = maxdia(root->right,max);

    if((lheight+rheight+1)>max)
      max = (lheight+rheight+1);

    if(lheight>rheight)
      return (lheight+1);

    else return (rheight+1);
  }
}


int main(){
  int nn,da,d,i,j;
  static int max;
  string s;
  cin>>nn>>da;
  struct node *root = newNode();
  root->data = da;


  for(i=0;i<(nn-1);i++){
    cin>>s>>d;
    insertion(root,s,d);
    //cout<<d<<endl;
}

  int height = maxdia(root,max);
  cout<<max<<endl;



  //inorderTraversal(root);
  return 0;
}
