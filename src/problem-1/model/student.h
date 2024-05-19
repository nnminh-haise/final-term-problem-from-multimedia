#ifndef __STUDENT__
#define __STUDENT__

#include <string>
#include <iostream>

class Student
{
private:
    int Index;

    std::string studentId;

    std::string firstName;

    std::string lastName;

    std::string classId;

    int grade;

public:
    int getIndex();

    std::string getStudentId();

    std::string getFirstName();

    std::string getLastName();

    std::string getAllName();

    std::string getReverseName();

    std::string getClassId();

    int getGrade();

    void setIndex(int Index);

    void setStudentId(std::string id);

    void setFirstName(std::string fName);

    void setLastName(std::string lName);

    void setClassId(std::string cId);

    void setGrade(int g);
};

#endif // __STUDENT__