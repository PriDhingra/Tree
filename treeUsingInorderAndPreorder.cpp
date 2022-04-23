#include<map>
class Solution{
    public:
    void createMapping(int in[], map<int, int> &m,int n) {
        for(int i = 0;i < n;i++) {
            m[in[i]] = i;
        }
        
    }
    Node* solve(int in[], int pre[], int &index, int startIndex,int lastIndex, int n, map<int, int> &m) {
        if(index >= n || startIndex > lastIndex)
            return NULL;
            
        int element = pre[index++];
        Node* temp = new Node(element);
        int position = m[element];
        
        temp -> left = solve(in, pre, index, startIndex, position - 1, n, m);
        temp -> right = solve(in, pre, index, position + 1, lastIndex, n, m);
        
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int, int> m;
        createMapping(in, m, n);
        // Code here
        int index = 0;
        Node* ans = solve(in, pre, index, 0, n - 1, n, m);
        return ans;
        
    }
};
