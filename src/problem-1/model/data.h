#ifndef __DATA__
#define __DATA__

#include <OpenXLSX.hpp>
#include <nowide/iostream.hpp>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <locale>
#include <map>
#include <set>
#include "student.h"
#include "output.h"

enum __COLOR_CONSOLE__
{
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLE,
    LIGHT_YELLOW,
    BRIGHT_WHITE
};

template <class value>
void BBsort(std::vector<value> &Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        for (int j = i + 1; j < Array.size(); j++)
        {
            if (Array[i] < Array[j])
                swap(Array[i], Array[j]);
        }
    }
}

class Data
{
private:
    std::vector<Student *> Students;
    std::map<std::string, bool> checkId;

public:
    Data(std::string path);

    size_t getNumberOfStudent();

    bool existId(std::string id);

    void refreshData(std::string path);

    void addData(std::string path, Student *student);

    void Remove(std::string path, Student *student);

    std::vector<Student *> getData();

    void printStudent(Student *student);

    void printStudentLowerThan(int grade);

    void printStudentHigherThan(int grade);

    void findStudentById(std::string ID);

    void findStudentByLastName(std::string lastName);

    void findStudentbyFirstName(std::string firstName);

    void findStudentbyClassId(std::string classId);

    void findStudentbyGrade(int grade);

    void sortStudentById();

    void sortStudentByLastName();

    void sortStudentbyFirstName();

    void sortStudentbyClassId();

    void sortStudentbyGrade();
};

#endif // __DATA__