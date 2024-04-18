#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

template <typename T>
class LinkedList {
    public:
    struct Node {
        Node() {
        }

        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }

        T data;
        Node* next;
    };

    public:
    void init() {
        this->head = nullptr;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    /**
     * This function will create a new node holds the given value
     * and add it to the beginning of the current list.
     * Time complexcity: O(1)
    */
    void pushFront(T value) {
        /**
         * Creating a new head node.
         * `newNode->next = this->head` means that this is pointing to
         * the current head node, which makes this node is the new one.
        */
        Node* newNode = new Node(value, this->head);
        this->head = newNode; // * This store the new head node.
    }

    /**
     * This function will create a new Node holds the given value
     * and add it to the end of the current list.
     * Time complexcity: assume the current list has n node, the function
     * will executed in O(n).
    */
    void pushBack(T value) {
        // * Creating a new last node.
        Node* newNode = new Node(value, nullptr);

        /**
         * This if statement resolve the case where the list is empty.
         * Then the head node is pointed to the newNode.
        */
        if (this->isEmpty()) {
            this->head = newNode;
            // Return to break out of the function also avoid an else statement.
            return;
        }

        // This while loop will travel to the last node of the current list.
        Node* lastNode = this->head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        // Connect the current last node with the new last node;
        lastNode->next = newNode;
    }

    /**
     * This function will create a new node holds the given value
     * then add this node right after the last node which has the
     * value of the target value.
    */
    void pushAfter(T targetingValue, T value) {
        Node* newNode = new Node(value, nullptr);

        // The list is empty means that the targeting value does not exist.
        if (this->isEmpty()) {
            throw std::underflow_error("Empty list!");
        }

        /**
         * This while loop wll search for the first node which has data equal
         * to the targeting value.
        */
        Node* targetingNode = this->head;
        while (targetingNode != nullptr && targetingNode->data != targetingValue) {
            targetingNode = targetingNode->next;
        }

        /**
         * The above loop will be ended in two cases:
         * 1. The targeting node is pointing to a null pointer
         * 2. The targeting node's data is equal to the targeting data.
         * This if statement resolve the first case. This case means that the
         * targeting value does not exist inside the list. Therefore, we cannot
         * perform the insert operation.
        */
        if (targetingNode == nullptr) {
            throw std::logic_error("Cannot find the targeting value!");
        }

        /**
         * This while loop will find the last node which has data equal to
         * the targeting value.
        */
        while (targetingNode->next != nullptr
            && targetingNode->next->data == targetingNode->data) {
            targetingNode = targetingNode->next;
        }

        // These tww lines of code insert the new node to the list
        newNode->next = targetingNode->next;
        targetingNode->next = newNode;
    }

    void print() {
        Node* head = this->head;
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    private:
    Node* head;
};

#endif // __LINKED_LIST__