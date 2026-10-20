#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& numbers, int lowIndex, int highIndex) {
    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    int pivot = numbers[midpoint];

    bool done = false;
    while (!done){
        while (numbers[lowIndex] < pivot){
            lowIndex += 1;
        }
        while (pivot < numbers[highIndex]) {
            highIndex -=1;
        }
    
        // If zero or one element remain, then all number are
        // partitioned
        if (lowIndex >= highIndex) {
            done = true;
        }
        else {
            //Swap numbers[lowIndex] and numbers[highIndex]
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            //Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

// print helper
void Quicksort(vector<int>& numbers, int lowIndex, int highIndex) {
    // Base case: 0 or 1 elements is already sorted
    if (lowIndex >= highIndex) {
        return;
    }

    //Partition, then sort each side
    int lowEndIndex = Partition(numbers, lowIndex, highIndex);
    Quicksort(numbers, lowIndex, lowEndIndex);
    Quicksort(numbers, lowEndIndex + 1, highIndex);
}

//Print helper
void PrintNumbers(const vector<int>& numbers) {
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
}

// entry point 
int main() {
    vector<int> numbers = {10, 2, 78, 4, 45, 32, 7, 11};

    cout << "Before";
    PrintNumbers(numbers);

    Quicksort(numbers, 0, numbers.size() - 1);

    cout << "After: ";
    PrintNumbers(numbers);

    return 0;
}