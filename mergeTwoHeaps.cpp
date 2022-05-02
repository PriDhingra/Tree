void heapify(vector<int> &arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < n && arr[largest] < arr[left])
		largest = left;
	
	if(right < n && arr[largest] < arr[right])
		largest = right;
	
	if(largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

vector<int> mergeHeap(vector<int> &arr1, vector<int> &arr2) {
	// Write your code here
	vector<int> arr;
	
	for(int i = 0;i < arr1.size();i++) {
		arr.push_back(arr1[i]);
	}
	
	for(int i = 0;i < arr2.size();i++) {
		arr.push_back(arr2[i]);
	}

	int n = arr.size();
	for(int i = n/2 - 1;i >= 0;i--) {
		heapify(arr, n, i);
	}
	
	return arr;
}
