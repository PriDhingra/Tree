int solve(TreeNode<int> *root, int &k) {
	if(root == NULL) {
		return -1;
	}
	
	int left = solve(root -> left, k);
	
	if(left != -1)
		return left;
	
	k--;
	if(k == 0) 
		return root -> data;
	
	return solve(root -> right, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
	int ans = solve(root, k);
	return ans;
}
