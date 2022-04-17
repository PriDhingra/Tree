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

void getVerticalOrder(Node* temp, int hd, map<int, vector<int>> &m) {
    if(temp == NULL)
        return;

    m[hd].push_back(temp -> data);

    getVerticalOrder(temp -> left, hd - 1, m);
    getVerticalOrder(temp -> right, hd + 1, m);
}

void verticalTraversing(Node* temp) {
    if(temp == NULL)
        return;

    map<int, vector<int> > m;
    int hd = 0;

    getVerticalOrder(temp, hd, m);

    for(auto i: m) {
        for(int j = 0;j < i.second.size();j++) {
            cout<<i.second[j]<<" ";
        }
    }
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    verticalTraversing(root);

    return 0;
}
