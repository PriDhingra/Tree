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

bool isTreeBalanced(Node* temp) {
    if(temp == NULL)
        return true;

    bool left = isTreeBalanced(temp -> left);
    bool right = isTreeBalanced(temp -> right);

    bool diff = abs(heightOfBinaryTree(temp -> left) - heightOfBinaryTree(temp -> right) <= 1);

    if(left && right && diff) 
        return true;
    else    
        return false;
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    if(isTreeBalanced(root)) {
        cout<<"Tree is balanced";
    } else {
        cout<<"Not balanced";
    }

    return 0;
}
