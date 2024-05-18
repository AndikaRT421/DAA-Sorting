#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<int> &vec, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && vec[left] > vec[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && vec[right] > vec[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(vec[i], vec[largest]);

        // Recursively heapify the affected sub-tree
        heapify(vec, n, largest);
    }
}

void heap_sort(vector<int> &vec) {
    int n = vec.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vec, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(vec[0], vec[i]);

        // call max heapify on the reduced heap
        heapify(vec, i, 0);
    }
}
