#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right){
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the two halves here
    // In zyBook: A, B, C, D then F C D
    // then F G then H
}

int main(){
    vector<int> arr = {8, 3, 5, 1, 4, 2};

    mergeSort(arr, 0, arr.size() - 1);

    return 0;
}