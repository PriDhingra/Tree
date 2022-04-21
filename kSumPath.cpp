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

void kSumPath(Node* temp, int k, int &count, vector<int> v1) {
    if(temp == NULL) {
        return;
    }
 
    v1.push_back(temp -> data);

    kSumPath(temp -> left, k, count, v1);
    kSumPath(temp -> right, k, count, v1);

    int sum = 0;
    for(int i = v1.size() - 1;i >= 0;i--) {
        sum += v1[i];
        if(sum == k) 
            count++;
    }

    v1.pop_back();
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    int k = 3;
    int count = 0;
    vector<int> v1;
    
    kSumPath(root, k, count, v1);
    cout<<"Total Path with "<<k<<" sum is : "<<count;

    return 0;
}
