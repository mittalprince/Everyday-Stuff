/* GIven n-ary tree and convert the same tree into binary tree */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 10;

struct Node {
    char data;
    vector<Node *> child;

    Node(char c): data(c) {
        child.resize(MAX, nullptr);
    }
};

void nary2binary(Node* root) {
    queue<Node *> q;
    stack<Node *> s;

    q.push(root);
    q.push(nullptr);
   
    while(q.empty() == false) {
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr) {
            s.push(nullptr);
        }
        else {
            s.push(temp);

            for(auto& i : temp->child) {
                if(i == nullptr)
                    break;
                q.push(i);
            }

            if(temp->child[0] != nullptr)
                q.push(nullptr);
        }
    }

    while(s.empty() == false) {
        Node* last = s.top();
        s.pop();

        while(s.empty() == false) {
            Node* second = s.top();
            s.pop();

            second->child[1] = last;
            last = second;

            for(int i = 2 ; i < MAX ; ++i) {
                second->child.at(i) = nullptr;
            }

            if(s.empty() == false && s.top() == nullptr)
                break;
        }
    }
}

void preorder(Node* root) {
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preorder(root->child.at(0));
    preorder(root->child.at(1));
}

int main() {
    Node *root = new Node('A');
    root->child[0] = new Node('B');
    root->child[1] = new Node('C');
    root->child[2] = new Node('D');
    root->child[3] = new Node('E');
    root->child[0]->child[0] = new Node('F');
    root->child[0]->child[1] = new Node('G');
    root->child[2]->child[0] = new Node('H');
    root->child[0]->child[0]->child[0] = new Node('I');
    root->child[0]->child[0]->child[1] = new Node('J');
    root->child[0]->child[0]->child[2] = new Node('K');
    root->child[2]->child[0]->child[0] = new Node('L');
    root->child[2]->child[0]->child[1] = new Node('M');

    nary2binary(root);
    preorder(root);

    cout<<endl;

    return 0;
}