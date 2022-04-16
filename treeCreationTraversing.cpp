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

void preOrderTraversal(Node* temp) {

    if(temp == NULL)
        return;

    cout<<temp -> data<<" ";
    preOrderTraversal(temp -> left);
    preOrderTraversal(temp -> right);
}

void postOrderTraversal(Node* temp) {

    if(temp == NULL)
        return;

    postOrderTraversal(temp -> left);
    postOrderTraversal(temp -> right);
    cout<<temp -> data<<" ";
}

void inOrderTraversal(Node* temp) {

    if(temp == NULL)
        return;

    inOrderTraversal(temp -> left);
    cout<<temp -> data<<" ";
    inOrderTraversal(temp -> right);
    
}

void levelOrderTraversal(Node* temp) {
    queue<Node*> q;
    q.push(temp);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp1 = q.front();
        q.pop();

        if(temp1 == NULL) {
            cout<<"\n";
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<temp1 -> data<<" ";
            if(temp1 -> left != NULL) 
                q.push(temp1 -> left);

            if(temp1 -> right != NULL)
                q.push(temp1 -> right);
        }
    }
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1

    preOrderTraversal(root);
    cout<<"\n";
    postOrderTraversal(root);
    cout<<"\n";
    inOrderTraversal(root);
    cout<<"\n";
    levelOrderTraversal(root);

    return 0;
}
