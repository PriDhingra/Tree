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

Node* kthAncestor(Node* temp, vector<int> &v1, int n1) {
    if(temp == NULL) {
        return NULL;
    }
 
    if(temp -> data == n1) {
        return temp;
    }

    Node* left = kthAncestor(temp -> left, v1, n1);
    Node* right = kthAncestor(temp -> right, v1, n1);

    if(left == NULL && right == NULL)
        return NULL;
    else if(left == NULL && right != NULL) {
        v1.push_back(temp -> data);
        return right;
    } else if(left != NULL && right == NULL) {
        v1.push_back(temp -> data);
        return left;
    } else 
        return NULL;

} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    int k = 2;
    int n1 = 9;
    vector<int> result;
    
    Node* r = kthAncestor(root, result, n1);

    if(result.size() < k) {
        cout<<"No ancestor";
    } else {
        cout<<result[k - 1];
    }

    return 0;
}
