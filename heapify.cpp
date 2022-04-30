#include<iostream>

using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size += 1;
        int index = size;

        arr[index] = val;

        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else 
                return;
        }
    }

    void deleteFromHeap() {
        if(size == 0)
            cout<<"Nothing to delete";

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;


            if(leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return; 
            }
        }
    }

    void print() {
        for(int i = 1;i <= size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void solve(int arr[], int size) {
    if(size == 0)
        return;

    for(int i = size / 1; i > 0;i--) {
        heapify(arr, size, i);
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.print();
    h.insert(30);
    h.print();
    h.insert(40);
    h.print();
    h.insert(20);
    h.print();
    h.insert(10);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    for(int i = 1;i < 6;i++) 
        cout<<arr[i]<<" ";

    cout<<endl;
    
    solve(arr, 6);

    for(int i = 1;i < 6;i++) 
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
