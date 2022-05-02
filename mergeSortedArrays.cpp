#include<queue>
class Node {
	public:
		int data;
		int row;
		int column;
	
	Node(int data, int row, int column) {
		this -> data = data;
		this -> row = row;
		this -> column = column;
	}
};

class compare {
	public:
		bool operator()(Node* a, Node* b) {
			return a -> data > b -> data;
		}
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
	priority_queue<Node*, vector<Node*>, compare> pq;
	for(int i = 0 ;i < k;i++) {
		Node* temp = new Node(kArrays[i][0], i, 0);
		pq.push(temp);
	}
	
	vector<int> ans;
	while(pq.size() > 0) {
		Node* temp = pq.top();
		ans.push_back(temp -> data); 
		pq.pop();
		
		int row = temp -> row;
		int column = temp -> column;
		
		if(column + 1 < kArrays[row].size()) {
			Node* next = new Node(kArrays[row][column + 1], row, column + 1);
			pq.push(next);
		}
	}
	
	return ans;
}
