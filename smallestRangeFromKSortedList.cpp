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

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
	int mini = 99999999;
	int maxi = -99999999;
	
	priority_queue<Node*, vector<Node*>, compare> pq;
	
	for(int i = 0;i < k;i++) {
		int element = a[i][0];
		mini = min(mini, element);
		maxi = max(maxi, element);
		pq.push(new Node(element, i, 0));
	}
	
	int start = mini;
	int end = maxi;
	
	while(!pq.empty()) {
		
		Node* temp = pq.top();
		pq.pop();
		
		mini = temp -> data;
		
		if(maxi - mini < end - start) {
			start = mini;
			end = maxi;
		}
		
		if(temp -> column + 1 < n) {
			maxi = max(maxi, a[temp -> row][temp -> column + 1]);
			pq.push(new Node(a[temp -> row][temp -> column + 1], temp -> row ,
							temp -> column + 1));
			 
		} else {
			break;
		}
	}
	
	return end - start + 1;
}
