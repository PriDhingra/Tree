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

bool searchInBST(Node* root, int searchElement) {
    if(root == NULL)
        return false;

    if(root -> data == searchElement)
        return true;

    if(root -> data > searchElement) 
        return searchInBST(root -> left, searchElement);
    else    
        return searchInBST(root -> right, searchElement);
}

int main() {
    Node* root = NULL;

    buildBST(root);
    levelOrderTraversal(root);

    int searchElement;
    cout<<"Enter element to search : ";
    cin>>searchElement;

    if(searchInBST(root, searchElement)) 
        cout<<"Element is present";
    else 
        cout<<"Element is not present";

    return 0;
}
