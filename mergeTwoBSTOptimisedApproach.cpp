void createDLL(TreeNode<int> *root, TreeNode<int> *&head) {
	if(root == NULL)
		return;
	
	createDLL(root -> right, head);
	
	root -> right = head;
	
	if(head != NULL)
		head -> left = root;
	
	head = root;
	
	createDLL(root -> left, head);
}

TreeNode<int> *mergeTwoLL(TreeNode<int> *head1, TreeNode<int> *head2) {
	TreeNode<int> *head = NULL;
	TreeNode<int> *tail = NULL;
	
	while(head1 != NULL && head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			if(head == NULL) {
				head = head1;
				tail = head1;
				head1 = head1 -> right;
			} else {
				tail -> right = head1;
				head1 -> left = tail;
				tail = head1;
				head1 = head1 -> right;
			}
		} else {
			if(head == NULL) {
				head = head2;
				tail = head2;
				head2 = head2 -> right;
			} else {
				tail -> right = head2;
				head2 -> left = tail;
				tail = head2;
				head2 = head2 -> right;
			}
		}
	}
	
	while(head1 != NULL) {
		tail -> right = head1;
		head1 -> left = tail;
		tail = head1;
		head1 = head1 -> right;
	}
	
	while(head2 != NULL) {
		tail -> right = head2;
		head2 -> left = tail;
		tail = head2;
		head2 = head2 -> right;
	}
	
	return head;
}

int noOfNodes(TreeNode<int> *root) {
	int count = 0;
	TreeNode<int> *temp = root;
	while(temp != NULL) {
		count++;
		temp = temp -> right;
	}
	
	return count;
}

TreeNode<int> *sortedLLToBST(TreeNode<int>*  &root, int n) {
	if(n <= 0 || root == NULL) {
		return NULL;
	}
	
	TreeNode<int> *left = sortedLLToBST(root, n/2);
	
	TreeNode<int> *head = root;
	head -> left = left;
	
	root = root -> right;
	
	head -> right = sortedLLToBST(root, n-n/2-1);
	
	return head;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
	TreeNode<int> *head1 = NULL;
	TreeNode<int> *head2 = NULL;
	createDLL(root1, head1);
	head1 -> left = NULL;
	createDLL(root2, head2);
	head2 -> left = NULL;
	TreeNode<int> *head = mergeTwoLL(head1, head2);
	int count = noOfNodes(head);
	
	return sortedLLToBST(head, count);
}
