class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        Node* pre = NULL;
        
        while(curr != NULL) {
            if(curr -> left != NULL) {
                pre = curr -> left;
                while(pre -> right != NULL)
                    pre = pre -> right;
                    
                pre -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            } 
            curr = curr -> right;
            
        }
        
        // curr = root;
        // while(curr != NULL){
        //     curr -> left = NULL;
        //     curr = curr -> right;
        // }
    }
};
