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

Node* lowestCommonAncestor(Node* temp, int n1, int n2) {
    if(temp == NULL) {
        return NULL;
    }

    if(temp -> data == n1 || temp -> data == n2) {
        return temp;
    }

    Node* left = lowestCommonAncestor(temp -> left, n1, n2);
    Node* right = lowestCommonAncestor(temp -> right, n1, n2);

    if(left == NULL && right != NULL) 
        return right;
    else if(left != NULL && right == NULL) 
        return left;
    else if(left != NULL && right != NULL) 
        return temp;
    else
        return NULL;
 
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;
    
    cout<<"Lowest Common Ancestor : "<<lowestCommonAncestor(root, 8, 27) -> data;

    return 0;
}
