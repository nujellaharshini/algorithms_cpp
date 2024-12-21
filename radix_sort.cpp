#include <iostream>

using namespace std;

class record{
public:
    int key[11];

    record() {
        for(int i=1; i<=10; i++)
            key[i] = 0;
    }
};

// Global variables that can be accessed anywhere. Not recommended for serious programming.
record* A;
int* C;
record* B;
int k = 4;
int arraySize;


void CountSort(int r){  // r is referred to key[r]
    for (int i = 0; i <= k; i++)
        C[i] = 0;

    for (int j = 1; j <= arraySize; j++)
        C[A[j].key[r]]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    for (int j = arraySize; j >= 1; j--) {
        B[C[A[j].key[r]]] = A[j];
        C[A[j].key[r]]--;
    }

    for (int j = 1; j <= arraySize; j++)
        A[j] = B[j];
}

void RadixSort(int d){
    for (int i = d; i >= 1; i--) {
        CountSort(i);
    }
}

int main(int argc,char **argv) {

    // Get the size of the sequence
    cin >> arraySize;

    A = new record[arraySize+1];
    B = new record[arraySize+1];
    C = new int[k+1];

    // Continue reading sequences until there is no more
    for(int i=1; i<=arraySize; i++) {
        for(int j=1; j<=10; j++) {
            cin >> A[i].key[j];
        }
    }

    // Radix Sort
    RadixSort(10);

    // Output
    for(int i=1; i<=arraySize; i++) {
        for(int j=1; j<=10; j++)
            cout << A[i].key[j] << ";";
        cout << endl;
    }

    // Free allocated space
    delete[] A;
    delete[] B;
    delete[] C;

    return 1;
}