#include<iostream>
#include<queue>

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

int heightOfBinaryTree(Node* temp) {
    if(temp == NULL)
        return 0;

    int left = heightOfBinaryTree(temp -> left);
    int right = heightOfBinaryTree(temp -> right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(Node* temp) {
    if(temp == NULL)
        return 0;

    int op1 = diameterOfBinaryTree(temp -> left);
    int op2 = diameterOfBinaryTree(temp -> right);
    int op3 = heightOfBinaryTree(temp -> left) + heightOfBinaryTree(temp -> right) + 1; 
    
    int ans = max(op1, max(op2, op3));
    return ans;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    cout<<"Diameter of Binary Tree "<<diameterOfBinaryTree(root); 

    return 0;
}
