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

void leftBoundary(Node* temp, vector<int> &result) {
    if(temp == NULL || (temp -> left == NULL && temp -> right == NULL)) {
        return;
    }

    result.push_back(temp -> data);

    if(temp -> left)
        leftBoundary(temp -> left, result);
    else    
        leftBoundary(temp -> right, result);
}

void leafNodes(Node* temp, vector<int> & result) {

    if(temp == NULL)
        return;

    if(temp -> left == NULL && temp -> right == NULL) {
        result.push_back(temp -> data);
        return;
    }

    if(temp -> left)
        leafNodes(temp -> left, result);
    
    if(temp -> right)
        leafNodes(temp -> right, result);
}

void rightBoundary(Node* temp, vector<int> &result) {
    if(temp == NULL || (temp -> right == NULL && temp -> left == NULL)) {
        return;
    }

    if(temp -> right)
        rightBoundary(temp -> right, result);
    else    
        rightBoundary(temp -> left, result);

    result.push_back(temp -> data);
}

vector<int> boundaryTraversal(Node* temp) {
    vector<int> result;
    if(temp == NULL)
        return result;

    result.push_back(temp -> data);
    leftBoundary(temp -> left, result);
    leafNodes(temp, result);
    if(temp -> right != NULL) 
        rightBoundary(temp -> right, result);

    return result;
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    vector<int> result = boundaryTraversal(root);

    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<" ";

    return 0;
}
