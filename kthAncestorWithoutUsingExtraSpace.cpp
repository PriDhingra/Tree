#include<iostream>
#include<queue>
#include<map>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* &root) {
    cout<<"Enter data to be inserted : ";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1)
        return NULL;

    cout<<"Enter data to be inserted on left of "<<data;
    root -> left = buildTree(root -> left);
    cout<<"Enter data to be inserted on right of "<<data;
    root -> right = buildTree(root -> right);

    return root;
}

Node* kthAncestor(Node* temp, int n1, int &k) {
    if(temp == NULL) {
        return NULL;
    }
 
    if(temp -> data == n1) {
        return temp;
    }

    Node* left = kthAncestor(temp -> left, n1, k);
    Node* right = kthAncestor(temp -> right, n1, k);

    if(left != NULL && right == NULL) {
        k--;
        if(k <= 0) { 
            k = INT_MAX;
            return temp;
        }
        else 
            return left;
    } 
    
    if(left == NULL && right != NULL) {
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return temp;
        }
        else 
            return right;
    } 

    return NULL;

} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    int k = 3;
    int n1 = 9;
    
   cout<<k<<" ancestor of "<<n1<<" is "<<kthAncestor(root, n1, k) -> data;

    return 0;
}
