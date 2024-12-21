#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int max(int a, int b, int c){
    return max(max(a,b), c);
}

int maxCrossingSum(int A[], int low, int middle, int high){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = middle; i >= low; i--){
        sum = sum + A[i];
        if (sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int j = middle + 1; j <= high; j++){
        sum = sum + A[j];
        if (sum > right_sum){
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int A[], int low, int high){
    int middle = (low + high) / 2;

    if (high == low){
        return A[low];
    }

    if (low > high){
        return INT_MIN;
    }

    return max(maxSubArraySum(A, low, middle),
               maxSubArraySum(A, middle + 1, high),
               maxCrossingSum(A, low, middle, high));
}

int main(){
    int input;
    cin >> input;
    int A[input];

    for (int i = 0; i < input; i++){
        cin >> A[i];
    }

    int max_sum = maxSubArraySum(A, 0, input - 1);
    cout << max_sum;

    return 0;
}