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

pair<int, int> maxNonAdjacentSum(Node* temp) {
    if(temp == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = maxNonAdjacentSum(temp -> left);
    pair<int, int> rightAns = maxNonAdjacentSum(temp -> right);

    pair<int, int> ans;
    ans.first = temp -> data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return ans; 
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    
    
    pair<int, int> result = maxNonAdjacentSum(root);
    cout<<max(result.first, result.second);

    return 0;
}
