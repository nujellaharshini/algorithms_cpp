#include <iostream>
#include <cstdlib>
using namespace std;

int random(int x, int y){
    int num = y - x + 1;
    int answer = rand() % num + x;
    return answer;
}

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++){
        if (A[j] <= x){
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int randomizedPartition(int A[], int p, int r){
    int i = random(p, r);
    swap(A[r], A[i]);
    return partition(A, p, r);
}

void randomizedQuickSort(int A[], int p, int r){
    if (p < r){
        int q = randomizedPartition(A, p, r);
        randomizedQuickSort(A, p, q - 1);
        randomizedQuickSort(A, q + 1, r);
    }
}
int main() {
    int input;
    cin >> input;
    int A[input];

    for (int i = 0; i < input; i++) {
        cin >> A[i];
    }

    randomizedQuickSort(A, 0, input - 1);
    for (int i = 0; i < input; i++){
        cout << A[i] << ";";
    }
    return 0;
}