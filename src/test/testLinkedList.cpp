#include <iostream>

#include "testLinkedList.h"

#include "src/model/linkedList.hpp"

void TestLinkedList::testPushAfterCase1() {
    LinkedList <int> list;

    try {
        list.init();
        list.pushAfter(10, 10);
        list.print();
    }
    catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

void TestLinkedList::testPushAfterCase2() {
    LinkedList <int> list;

    try {
        list.init();
        list.pushFront(10);
        list.pushAfter(100, 12);
        list.print();
    }
    catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

void TestLinkedList::testPushAfterCase3() {
    LinkedList <int> list;

    try {
        list.init();
        list.pushFront(10);
        list.pushAfter(10, 11);
        list.print();
    }
    catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}