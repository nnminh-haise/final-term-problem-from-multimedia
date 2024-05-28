# Final term project

---

## Table of content

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Table of content](#table-of-content)
- [Problem 1 - Simple student manager](#problem-1---simple-student-manager)
- [Problem 2](#problem-2)
  - [Problem 2.1 - The knight tour problem](#problem-21---the-knight-tour-problem)
  - [Problem 2.2 - Binary search tree](#problem-22---binary-search-tree)
- [Solution for problem 1](#solution-for-problem-1)
  - [The student class](#the-student-class)
- [Solution for problem 2](#solution-for-problem-2)
  - [Problem 2.1](#problem-21)
  - [Problem 2.2](#problem-22)
- [Contributor list](#contributor-list)
  - [Rule for contributors](#rule-for-contributors)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2-1)

<!-- /code_chunk_output -->

---

## How to run

If you want to build this project, you need install Cmake, Vissual studio build tool 2022

- Cmake: [Here](https://cmake.org/download/)
- Visual studio build tool: [Here](https://aka.ms/vs/17/release/VC_redist.x64.exe)

## Problem 1 - Simple student manager

Build a student class with these attributes **(1.5 points)**:

- Student ID: a string includes both digits and letters.
- First name: a string.
- Last name: a string.
- Class: a string, can assume that this is the class ID.
- Grade: a double.

Implement these functionalities:

1. Import student's data from an Excel spreadsheet.

   - When importing the data, the user gets to choose the data structures they want. Here are the options: **(1 point)**
     - Array
     - Single linked list
     - Circular linked list
     - Double linked list

2. Build a search box, so that the user can search the student by: Student's ID, first name, last name, grade, class ID (ignore case) **(1.5 points)**.

   - There is an option where the user can reverse the output result from the search box. For example: if the result is "ABC", then when the reverse option is enabled, the output of the result should be "CBA".
   - The output should highlight the targeting student (could be bold or colored red).
   - Print the searching time.

3. Build the add new student functionality **(1 point)**.
4. Build the remove student functionality by their student's ID **(1 point)**.
5. Build the functionality, which lets the user to **(1 point)**:

   - List all students with the lowest grade.
   - List all students with the highest grade.
   - Calculate the average grade of the class.

6. Build the functionality, which allows the user to **(1 point)**:
   - Sort the student list by these algorithms:
     - Heap sort
     - Merge sort
     - Buble sort
     - Insertion sort
     - Quick sort
     - Selection sort
   - Let the user to choose which field to search by: student's ID, first name, last name or grade.
   - Showing the result after the sorting process and the time that consumed.

## Problem 2

Student choose to finish one of these problems. Each problem will have **2 points**.

### Problem 2.1 - The knight tour problem

Give a chess board with $n \times n$ squares.

Build a problem that lets the user to enter the number $n$ and the beginning coordinates of the knight $(u, v)$. Using a two dimensional array to store the chess board. List all the steps of the knight when it travel through all the squares on the board, each square will be visited one time only. Display the result as the follow format: $k: (u, v)$ where $k$ is the step's order and $(u, v)$ is the corresponding coordinates of the knight.

### Problem 2.2 - Binary search tree

Using the information from [the first problem](#problem-1---simple-student-manager), build a functionality that allows the user to build a binary search tree from the student list. Each node of the tree includes: grade as key and info is the number of student who has the same grade.

The program should:

- Allow the user to add a new node.
- Remove a node with the given key.
- Traverse throught the tree by these algorithms: PreOrder, InOrder, PostOrder (recursive algorithm or non-recursive algorithm).

Remember to display the result and the processing time when displaying the result.

---

## Solution for problem 1

### The student class

The student class's definition is defined inside the directory: `src/problem-1/model/student*`

- The `student.h` file is the class's definition, which includes the class definition and the class's methods definition.
- The `student.h` file is the class's methods implementation.

Here is the link to the `student.h` file: [Link](./src/problem-1/model/student.h).

Here is the link to the `student.cpp` file: [Link](./src/problem-1/model/student.cpp).

## Solution for problem 2

### Problem 2.1

### Problem 2.2

---

## Contributor list

### Rule for contributors

- Every contributor when working must create a separate branch and create a pull request before merging into the main branch.
- The branch name and commit message mush follow this convention: [git branch name and commit message convetion](https://dev.to/varbsan/a-simplified-convention-for-naming-branches-and-commits-in-git-il4).

### Problem 1

| Feature                                                | STATUS     | FILE           | Contributor       |
| :----------------------------------------------------- | :--------- | :------------- | :---------------- |
| 0 - Student class                                      | DONE       |                | Nguyen Nhat Minh  |
| 1 - Import data from excel file (.xlsx) using OpenXLSX | DONE       |                | Nguyen Thanh Vinh |
| 1.1- Read UTF-8 data                                   | BUG        | model/data.cpp | Nguyen Thanh Vinh |
| 2 - Print list of students                             | DONE       |                | Nguyen Thanh Vinh |
| 3 - Add student to the list                            | DONE       |                | Nguyen Thanh Vinh |
| 4 - Remove student from the list                       | DONE       |                | Nguyen Thanh Vinh |
| 5 - Find student and reverse name                      | DONE (3/5) | model/data.cpp | Nguyen Thanh Vinh |
| 6 - Print list of students with highest(lowest) grade  | DONE       |                | Nguyen thanh Vinh |
| 7 - Sort list (bubble sort)                            | DONE (3/5) | model/data.cpp | Nguyen thanh Vinh |

### Problem 2

**Problem 2.1:**

|     | NAME        | Status       | Contributor       |
| :-- | :---------- | :----------- | :---------------- |
| 1   | problem-2.1 | WRONG ANSWER | Nguyen Thanh Vinh |
| 2   | Knight      | DONE         | Luong Minh Khoi   |

**Problem 2.2:**

|     | Name | Status      | Contributor     |
| :-- | :--- | :---------- | --------------- |
| 1   |      | IN PROGRESS | Luong Minh Khoi |

---
