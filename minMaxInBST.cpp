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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<< endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<temp -> data<<" ";
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

Node* insertInBST(Node* root, int data) {
    if(root == NULL) {
        Node* temp = new Node(data);
        return temp;
    }

    if(data < root -> data) {
        root -> left = insertInBST(root -> left, data);
    } else {
        root -> right = insertInBST(root -> right, data);
    }

    return root;
}

void buildBST(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertInBST(root, data);
        cin>>data;
    }
}

Node* minElementInBST(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL)
        temp = temp -> left;

    return temp;
}

Node* maxElementInBST(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL)
        temp = temp -> right;

    return temp;
}

int main() {
    Node* root = NULL;

    buildBST(root);
    levelOrderTraversal(root);

    cout<<"Minimum Element in BST "<<minElementInBST(root) -> data<<endl;
    cout<<"Maximum Element in BST "<<maxElementInBST(root) -> data;

    return 0;
}
