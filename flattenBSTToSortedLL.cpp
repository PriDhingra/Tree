void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &v1) {
	if(root == NULL)
		return;
	
	inorder(root -> left, v1);
	v1.push_back(root);
	inorder(root -> right, v1);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
	vector<TreeNode<int>*> v1;
	inorder(root, v1);
	
	for(int i = 0;i < v1.size() - 1;i++) {
		v1[i] -> left = NULL;
		v1[i] -> right = v1[i + 1];
	}
	
	v1[v1.size() - 1] -> left = NULL;
	v1[v1.size() - 1] -> right = NULL;
	
	return v1[0];
}
