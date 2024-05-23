#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class MinHeap {
public:
    MinHeap() = default;

    void push(const T& value) {
        heap.push_back(value);
        push_heap(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        if (!heap.empty()) {
            pop_heap(0);
        }
    }

    const T& top() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap.front();
    }

    bool empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }

private:
    std::vector<T> heap;

    void push_heap(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (heap[index] >= heap[parent]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void pop_heap(size_t index) {
        size_t size = heap.size();
        while (true) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
};

int main() {
    MinHeap<int> heap;

    heap.push(3);
    heap.push(1);
    heap.push(4);
    heap.push(1);
    heap.push(5);
    heap.push(9);
    heap.push(2);
    heap.push(6);
    heap.push(5);
    heap.push(3);
    heap.push(5);

    std::cout << "Heap size: " << heap.size() << std::endl;

    while (!heap.empty()) {
        std::cout << heap.top() << " ";
        heap.pop();
    }
    std::cout << std::endl;

    return 0;
}
