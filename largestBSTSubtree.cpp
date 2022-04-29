class info {
	public :
		int maxi;
		int mini;
		bool isBST;
		int size;
};

info solve(TreeNode<int>* root, int &maxSize) {
	if(root == NULL) {
		return {INT_MIN, INT_MAX, true, 0};
	}
	
	info left = solve(root -> left, maxSize);
	info right = solve(root -> right, maxSize);
	
	info ans;
	ans.size = left.size + right.size + 1;
	ans.maxi = max(root -> data, right.maxi);
	ans.mini = min(root -> data, left.mini);
	
	if(left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini)) {
		ans.isBST = true;
	} else {
		ans.isBST = false;
	}
	
	if(ans.isBST) {
		maxSize = max(maxSize, ans.size);
	}
	
	return ans;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
	int maxSize = 0;
	info temp = solve(root, maxSize);
	return maxSize;
}
