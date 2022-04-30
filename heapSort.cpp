#include<iostream>

using namespace std;

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= size && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right <= size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    int t = size;

    while(t > 1) {
        swap(arr[1], arr[t]);
        t--;
        heapify(arr, t, 1);
    }
}

int main() {

    int arr[6] = {-1, 70, 60, 55, 45, 50};

    cout<<"Before Sorting : ";
    for(int i = 1;i < 6;i++) 
        cout<<arr[i]<<" ";

    cout<<endl;
    
    heapSort(arr, 5);

    cout<<"After Sorting : ";
    for(int i = 1;i < 6;i++) 
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
