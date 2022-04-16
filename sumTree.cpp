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

pair<bool, int> isSumTreeFast(Node* temp) {
    if(temp == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(temp -> left == NULL && temp -> right == NULL) {
        pair<bool, int> p = make_pair(true, temp -> data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(temp -> left);
    pair<bool, int> rightAns = isSumTreeFast(temp -> right); 

    bool first = leftAns.first;
    bool second = rightAns.first;

    bool condition =   temp -> data == leftAns.second + rightAns.second;

    pair<bool, int> ans;
    if(first && second && condition) {
        ans.first = true;
        ans.second = 2 * temp -> data;
    } else {
        ans.first = false;
    }

    return ans;
}

bool sumTree(Node* temp) {
    return isSumTreeFast(temp).first;
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    if(sumTree(root)) {
        cout<<"Tree is SumTree";
    } else {
        cout<<"Tree is not SumTree";
    }

    return 0;
}
