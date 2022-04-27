BinaryTreeNode<int>* createBST(vector<int> &preorder, int &i, int mini, int maxi) {
	if(i >= preorder.size() || preorder[i] < mini || preorder[i] > maxi)
		return NULL;
	
	BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(preorder[i++]);
	temp -> left = createBST(preorder, i, mini, temp -> data);
	temp -> right = createBST(preorder, i, temp -> data, maxi);
	
	return temp;
}


BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
	int mini = INT_MIN;
	int maxi = INT_MAX;
	int index = 0;
	return createBST(preorder, index, mini, maxi);
}
