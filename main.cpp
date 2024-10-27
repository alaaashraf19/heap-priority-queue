#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cerr << "Heap is empty\n";
            return -1;  // Sentinel value
        }
        if (heap.size() == 1) {
            int minValue = heap.back();
            heap.pop_back();
            return minValue;
        }

        int minValue = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            cerr << "Heap is empty\n";
            return -1;  // Sentinel value
        }
        if (heap.size() == 1) {
            int maxValue = heap.back();
            heap.pop_back();
            return maxValue;
        }

        int maxValue = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }
void buildMaxHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }


    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
void heapSort(vector<int>& arr) {
    MaxHeap maxHeap;
    maxHeap.buildMaxHeap(arr);

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[n - 1 - i] = maxHeap.extractMax(); // Place max element at the end
    }
}

class PriorityQueue {
private:
    MaxHeap heap;

public:
    void insert(int priority) {
        heap.insert(priority);
    }

    int extractHighestPriority() {
        return heap.extractMax();
    }

    void printQueue() {
        heap.printHeap();
    }
};
int main() {
    // Testing MinHeap
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);

    cout << "MinHeap elements: ";
    minHeap.printHeap();
    cout << "Extracted Min: " << minHeap.extractMin() << endl;
    cout << "MinHeap after extracting min: ";
    minHeap.printHeap();

    // Testing MaxHeap
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);

    cout << "MaxHeap elements: ";
    maxHeap.printHeap();
    cout << "Extracted Max: " << maxHeap.extractMax() << endl;
    cout << "MaxHeap after extracting max: ";
    maxHeap.printHeap();

    PriorityQueue pq;

    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(30);

    cout << "Priority Queue elements: ";
    pq.printQueue();

    // Extracting the highest priority element
    int highest = pq.extractHighestPriority();
    cout << "Extracted highest priority element: " << highest << endl;

    cout << "Priority Queue after extraction: ";
    pq.printQueue();


    vector<int> arr = {40, 10, 30, 20, 50};
    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
