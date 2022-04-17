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

vector<int> zigZagTraversal(Node* temp) {
    vector<int> result;

    if(temp == NULL) 
        return result;

    queue<Node*> q;
    q.push(temp);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        for(int i = 0;i < size;i++) {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data; 
        
            if(frontNode -> left) 
                q.push(frontNode -> left);

            if(frontNode -> right) 
                q.push(frontNode -> right);
        }

        leftToRight = !leftToRight;

        for(auto i : ans) 
            result.push_back(i);
    }

    return result;
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    vector<int> result = zigZagTraversal(root);

    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<" ";

    return 0;
}
