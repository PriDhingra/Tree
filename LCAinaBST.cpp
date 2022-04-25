TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
	if(root == NULL)
		return NULL;
	
	if(P -> data > root -> data && Q -> data > root -> data)
		return LCAinaBST(root -> right, P, Q);
	
	if(P -> data < root -> data && Q -> data < root -> data)
		return LCAinaBST(root -> left, P, Q);
	
	return root;
}
