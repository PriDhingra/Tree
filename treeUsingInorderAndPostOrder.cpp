void createMapping(int in[], map<int, int> &m, int n) {
    for(int i = 0;i < n;i++) {
        m[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int index, int startIndex, int lastIndex, 
        map<int, int> &m, int n) {
    if(index < 0 || startIndex > lastIndex)
        return NULL;
    
    int element = post[index--];
    Node* temp = new Node(element);
    int position = m[element];
    
    temp -> right = solve(in, post, index, position + 1, lastIndex, m, n);
    temp -> left = solve(in, post, index, startIndex, position - 1, m, n);
    
    return temp;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int, int> m;
    createMapping(in, m, n);
    Node* ans = solve(in, post, n - 1, 0, n -1, m, n);
    return ans;
}
