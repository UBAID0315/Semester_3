#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    int getParent(int child) {
        return (child - 1) / 2;
    }

    int getLeft(int parent) {
        return 2 * parent + 1;
    }

    int getRight(int parent) {
        return 2 * parent + 2;
    }

    void swap(int a, int b) {
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[getParent(index)]) {
            swap(index, getParent(index));
            index = getParent(index);
        }
    }

    void heapifyDown(int index) {
        int left = getLeft(index);
        int right = getRight(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(largest, index);
            heapifyDown(largest);
        }
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void updateValue(int oldValue, int newValue) {
        int index = -1;

        // Search for the old value in the heap
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == oldValue) {
                index = i;
                break;
            }
        }

        // If the old value is found, update and heapify
        if (index != -1) {
            heap[index] = newValue;
            if (newValue > heap[getParent(index)]) {
                heapifyUp(index);
            } else {
                heapifyDown(index);
            }
            cout << "Value updated successfully." << endl;
        } else {
            cout << "Value not found in the heap." << endl;
        }
    }
    void deleteElement(int value, int inc) 
    {
            int index = -1;
            for (int j = 0; j < heap.size(); ++j) 
            {
                if (heap[j] == value) 
                {
                    index = j;
                    break;
                }
            }

            // Check if element exists and remove
            if (index != -1) 
            {
            // Swap element with last element and update size
                heap[index] = heap.back();
                heap.pop_back();
                heapifyDown(index);
                cout << "Value " << value << " deleted successfully." << endl;
            }
            else 
            {
                cout << "Value " << value << " not found in the heap." << endl;
            }
    }

    bool searchValue(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                return true;
            }
        }
        return false;
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Max Heap: ";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
     MaxHeap maxHeap;

     maxHeap.insert(5);
     maxHeap.insert(3);
     maxHeap.insert(8);
     maxHeap.insert(1);
     maxHeap.insert(7);

     maxHeap.display();

     // Example of updating and searching
     maxHeap.updateValue(3, 10);
     maxHeap.display();

     if (maxHeap.searchValue(8)) {
         cout << "Value 8 exists in the heap." << endl;
     } else {
         cout << "Value 8 does not exist in the heap." << endl;
     }

     return 0;
 }

