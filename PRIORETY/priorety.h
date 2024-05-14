#include <iostream>
#include <stdexcept>

template<typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
    };

    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return !head;
    }

    void push(const T& value, int priority) {
        Node* newNode = new Node{ value, priority, nullptr };

        if (!head || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return head->data;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << "Value: " << current->data << ", Priority: " << current->priority << endl;
            current = current->next;
        }
    }
};