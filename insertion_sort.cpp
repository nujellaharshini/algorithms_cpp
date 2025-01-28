#include <iostream>
#include <vector>
using namespace std;
/**
    for j = 2 to n
        key = A[j]
        i = j - 1
        while i > 0 and A[i] > key
            A[i + 1] = A[i]
            i = i - 1
        A[i - 1] = key
**/

void insertionSort(vector<int>& arr){
    int l = arr.size();
    for (int i = 1; i < l; i++){
        int key = arr[i];
        int j = i - 1;

        //moving to the correct location
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        //printing the solution
        for (int k = 0; k <= i; k++){
            cout << arr[k] <<";";
        }
        cout << endl;

    }
}

int main(){
    int input;
    cin >> input;

    vector<int> arr(input);
    for (int i = 0; i < input; i++){
        cin >> arr[i];
    }

    insertionSort(arr);

    return 0;

}
