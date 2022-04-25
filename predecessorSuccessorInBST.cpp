vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	// Write your code here.
	int pred = -1;
	int succ = -1;
	
	while(root -> data != key) {
		if(root -> data > key) {
			succ = root -> data; 
			root = root -> left;
		} else {
			pred = root -> data;
			root = root -> right;
		}
	}
	
	binaryTreeNode *temp1 = root -> left;
	binaryTreeNode *temp2 = root -> right;
	
	while(temp1 != NULL) {
		pred = temp1 -> data;
		temp1 = temp1 -> right;
	}
	
	while(temp2 != NULL) {
		succ = temp2 -> data;
		temp2 = temp2 -> left;
	}
	
	return {pred, succ};
}
