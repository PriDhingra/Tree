void solve(BinaryTreeNode<int>* root, vector<int> &v1) {
	if(root == NULL)
		return;
	
	solve(root -> left, v1);
	v1.push_back(root -> data);
	solve(root -> right, v1);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
	vector<int> v1;
	solve(root, v1);
	
	int i = 0;
	int j = v1.size() - 1;
	
	while(i < j) {
		int sum = v1[i] + v1[j];
		
		if(sum == target) {
			return true;
// 			return;
		}
		else if(sum > target)
			j--;
		else
			i++;
	}
	
	return false;
}
