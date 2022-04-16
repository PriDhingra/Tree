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

pair<bool, int> isBalancedFast(Node* temp){
    if(temp == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(temp -> left);
    pair<bool, int> right = isBalancedFast(temp -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff) 
        ans.first = true;
    else    
        ans.first = false;

    return ans;
}

bool isTreeBalanced(Node* temp) {
    return isBalancedFast(temp).first;
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
