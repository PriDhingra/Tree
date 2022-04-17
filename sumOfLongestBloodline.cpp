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

void sumOfLongestBloddLine(Node* temp, int len, int &maxLen, int sum, int &maxSum) {
    if(temp == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + temp -> data;

    sumOfLongestBloddLine(temp -> left, len + 1, maxLen, sum, maxSum);
    sumOfLongestBloddLine(temp -> right, len + 1, maxLen, sum, maxSum);
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;
    
    sumOfLongestBloddLine(root, len, maxLen, sum, maxSum);
    cout<<"Sum of longest bloddline : "<<maxSum;

    return 0;
}
