bool isCBT(BinaryTreeNode<int>* root, int i, int nodeCount) {
	if(root == NULL) {
		return true;
	}
	
	if(i >= nodeCount)
		return false;
	else {
		bool left = isCBT(root -> left, (2 * i + 1), nodeCount);
		bool right = isCBT(root -> right, (2 * i + 2), nodeCount);
		
		return (left && right);
	}
}

bool isHeap(BinaryTreeNode<int>* root) {
	if(root -> left == NULL && root -> right == NULL)
		return true;
	
	if(root -> right == NULL) {
		return (root -> data >= root -> left -> data);
	} else {
		bool left = isHeap(root -> left);
		bool right = isHeap(root -> right);
		
		return (left && right && (root -> data >= root -> left -> data 
		   && root -> data >= root -> right -> data));
			
	}
}

int countNode(BinaryTreeNode<int>* root) {
	if(root == NULL)
		return 0;
	
	int ans = 1 + countNode(root -> left) + countNode(root -> right);
	return ans;
}

bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    // Write your code here.
	int index = 0;
	int totalCount = countNode(root);
	if(isCBT(root, index, totalCount) && isHeap(root))
		return true;
	else
		return false;
	
}
