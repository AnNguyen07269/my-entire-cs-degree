#include <iostream>
#include <vector>

// Function to perform Insertion Sort
void insertionSort(std::vector<int>& vec) {
    int n = vec.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        // Move elements of vec[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        // Insert the key into its correct sorted position
        vec[j + 1] = key;
    }
}

// Helper function to print the vector
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6};

    std::cout << "Original array: ";
    printVector(data);

    // Perform insertion sort
    insertionSort(data);

    std::cout << "Sorted array:   ";
    printVector(data);

    return 0;
}
