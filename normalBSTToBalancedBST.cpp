void inorder(TreeNode<int>* root, vector<int> &v1) {
	if(root == NULL)
		return;
	
	inorder(root -> left, v1);
	v1.push_back(root -> data);
	inorder(root -> right, v1);
}

TreeNode<int>* createBST(vector<int> &v1, int start, int end) {
	if(start > end)
		return NULL;
	
	int mid = start + (end - start) / 2;
	TreeNode<int>* temp = new TreeNode<int>(v1[mid]);
	temp -> left = createBST(v1, start, mid - 1);
	temp -> right = createBST(v1, mid + 1, end);
	
	return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
	vector<int> v1;
	inorder(root, v1);
	
	return createBST(v1, 0, v1.size() - 1);
}
