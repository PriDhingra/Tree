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

void topView(Node* temp) {
    map<int, int> m;

    queue<pair<Node*, int> >q;
    q.push(make_pair(temp, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode= temp.first;
        int hd = temp.second;

        if(m.count(hd) == 0) {
            m[hd] = frontNode -> data;
        }

        if(frontNode -> left) 
            q.push(make_pair(frontNode -> left, hd - 1));

        if(frontNode -> right) 
            q.push(make_pair(frontNode -> right, hd + 1));
    }

    for(auto i: m) {
            cout<<i.second<<" ";
    }
} 

int main() {
    Node* root = NULL;

    root = buildTree(root);

    //2 3 5 -1 -1 -1 4 -1 -1
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 10 11 -1 -1 -1
    topView(root);

    return 0;
}
