#include <iostream>
#include <windows.h>
#include "model/data.h"

enum __MAIN_MENU__
{
    OPTION_PRINT_LIST = 1,
    OPTION_FIND_FROM_LIST = 2,
    OPTION_ADD_TO_LIST = 3,
    OPTION_REMOVE_FROM_LIST = 4,
    OPTION_PRINT_LOWEST_GRADE = 5,
    OPTION_PRINT_HIGHEST_GRADE = 6,
    OPTION_SORT_LIST = 7,
    APPLICATION_EXIT = 8
};

enum __BY__
{
    BY_ID = 1,
    BY_LAST_NAME = 2,
    BY_FIRST_NAME = 3,
    BY_CLASS_ID = 4,
    BY_GRADE = 5
};

int main()
{
    int lowGrade = 5, highGrade = 8;
    std::string path = "DSSV.xlsx";
    std::string Menu = "1. Print list of students\n2. Find student (and reverse name student) \n3. Add new student to the list\n4. Remove student from the list\n5. Print list of students with lowest grade(< 5)\n6. Print list of students with highest grade(>= 8)\n7. Sort(use bubble sort)\n8. Exit\nOption: ",
                Menu1 = " student by:\n1. ID\n2. Last name\n3. First name\n4. Class id\n5. Grade\nOption: ",
                invalidOption = "Invalid option. Please type again!\n";
    bool flag = true;
    Data students(path);
    while (flag)
    {
        int Option;
        std::cout << Menu;
        std::cin >> Option;
        switch (Option)
        {
        case OPTION_PRINT_LIST:
        {
            for (size_t i = 0; i < students.getNumberOfStudent(); i++)
            {
                students.printStudent(students.getData()[i]);
            }
            break;
        }
        case OPTION_FIND_FROM_LIST:
        {
            int optionFind;
            std::cout << "Find " << Menu1;
            std::cin >> optionFind;
            switch (optionFind)
            {
            case BY_ID:
            {
                std::string id;
                std::cout << "Enter id: ";
                std::cin >> id;
                students.findStudentById(id);
                break;
            }
            case BY_LAST_NAME: // BUG: Can't get exactly UTF-8 characters -> can't get value
            {
                std::string lastName;
                std::cout << "Enter last name: ";
                nowide::cin.ignore();
                std::getline(nowide::cin, lastName);
                students.findStudentByLastName(lastName);
                break;
            }
            case BY_FIRST_NAME: // BUG: Can't get exactly UTF-8 characters -> can't get value
            {
                std::string firstName;
                std::cout << "Enter first name: ";
                nowide::cin.ignore();
                std::getline(nowide::cin, firstName);
                students.findStudentbyFirstName(firstName);
                break;
            }
            case BY_CLASS_ID:
            {
                std::string classId;
                std::cout << "Enter id: ";
                std::cin >> classId;
                students.findStudentbyClassId(classId);
                break;
            }
            case BY_GRADE:
            {
                int grade;
                std::cout << "Enter grade: ";
                std::cin >> grade;
                students.findStudentbyGrade(grade);
                break;
            }
            default:
                std::cout << invalidOption;
                break;
            }
            break;
        }
        case OPTION_ADD_TO_LIST:
        {
            std::string id, lastName, firstName, classId;
            int grade;
            Student *newStudent = new Student();
            nowide::cout << "ID: ";
            nowide::cin >> id;
            nowide::cout << "Last name: ";
            nowide::cin.ignore();
            std::getline(nowide::cin, lastName);
            nowide::cout << "First name: ";
            nowide::cin >> firstName;
            nowide::cout << "Class id: ";
            nowide::cin >> classId;
            nowide::cout << "Grade: ";
            nowide::cin >> grade;
            newStudent->setStudentId(id);
            newStudent->setLastName(lastName);
            newStudent->setFirstName(firstName);
            newStudent->setClassId(classId);
            newStudent->setGrade(grade);
            students.addData(path, newStudent);
            break;
        }
        case OPTION_REMOVE_FROM_LIST:
        {
            std::string ID;
            std::cout << "Input ID you want to remove: ";
            std::cin >> ID;
            students.Remove(path, ID);
            break;
        }
        case OPTION_PRINT_LOWEST_GRADE:
        {
            students.printStudentLowerThan(lowGrade);
            break;
        }
        case OPTION_PRINT_HIGHEST_GRADE:
        {
            students.printStudentHigherThan(highGrade);
            break;
        }
        case OPTION_SORT_LIST:
        {
            int optionSort;
            std::cout << "Sort " << Menu1;
            std::cin >> optionSort;
            switch (optionSort)
            {
            case BY_ID:
            {
                students.sortStudentById();
                break;
            }
            case BY_LAST_NAME: // BUG: Can't get exactly UTF-8 characters -> can't sort exactly
            {
                students.sortStudentByLastName();
                break;
            }
            case BY_FIRST_NAME: // BUG: Can't get exactly UTF-8 characters -> can't sort exactly
            {
                students.sortStudentbyFirstName();
                break;
            }
            case BY_CLASS_ID:
            {
                students.sortStudentbyClassId();
                break;
            }
            case BY_GRADE:
            {
                students.sortStudentbyGrade();
                break;
            }

            default:
                std::cout << invalidOption;
                break;
            }
            break;
        }
        case APPLICATION_EXIT:
        {
            flag = !flag;
            std::cout << "Bye" << std::endl;
            break;
        }
        default:
        {
            std::cout << invalidOption;
            break;
        }
        }
        system("pause&cls");
    }
    return 0;
}
// BUG: string can't get exactly UTF-8 characters