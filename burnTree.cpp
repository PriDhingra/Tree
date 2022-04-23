class Solution {
  public:
    Node* mappingChildToParent(Node* root, int target, map<Node*, Node*> &ctp) {
        queue<Node*> q;
        q.push(root);
        ctp[root] = NULL;
        Node* result = NULL;
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            if(temp -> data == target) {
                result = temp;
            }
            
            if(temp -> left) {
                ctp[temp -> left] = temp;
                q.push(temp -> left);
            }
            
            if(temp -> right) {
                ctp[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
        
        return result;
    }  
    
    int burnTree(Node* root, map<Node*, Node*> &ctp) {
        int ans = 0;
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        
        visited[root] = true;
        
        while(!q.empty()) {
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i < size;i++) {
                Node* front = q.front();
                q.pop();
                
                if(front -> left != NULL && !visited[front -> left]) {
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                
                if(front -> right != NULL && !visited[front -> right]) {
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                
                if(ctp[front] && !visited[ctp[front]]) {
                    flag = 1;
                    q.push(ctp[front]);
                    visited[ctp[front]] = true;
                }
            }
            
            if(flag == 1) 
                ans++;
        }
        
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> ctp;
        Node* resultNode = mappingChildToParent(root, target, ctp);
        
        return burnTree(resultNode, ctp);
    }
};
