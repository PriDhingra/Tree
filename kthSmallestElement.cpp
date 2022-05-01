#include<queue>

int kthSmallest(vector<int> input, int k)
{
    // Write your code here.
	priority_queue<int> pq;
	
	for(int i = 0;i < k ;i++) {
		pq.push(input[i]);
	}
	
	for(int i = k;i < input.size();i++) {
		if(input[i] < pq.top()) {
			pq.pop();
			pq.push(input[i]);
		}	
	}
	
	return pq.top();
}
