#include <iostream>
using namespace std;

void maxHeapify(int A[], int i, int size){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && A[left] > A[largest]){
        largest = left;
    } else {
        largest = i;
    }

    if (right < size && A[right] > A[largest]){
        largest = right;
    }

    if (largest != i){
        swap(A[i], A[largest]);
        maxHeapify(A, largest, size);
    }
}

void buildMaxHeap(int A[], int size){
    for (int i = size/2 - 1; i >= 0; i--){
        maxHeapify(A, i, size);
    }
}

void heapSort(int A[], int size){
    buildMaxHeap(A, size);
    for (int i = size - 1; i >= 0; i--){
        swap(A[0], A[i]);
        maxHeapify(A, 0, i);
    }
}

int main() {
    int input;
    cin >> input;
    int A[input];

    for (int i = 0; i < input; i++) {
        cin >> A[i];
    }

    heapSort(A, input);
    for (int i = 0; i < input; i++){
        cout << A[i] << ";";
    }
    return 0;
}