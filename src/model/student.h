#ifndef __STUDENT__
#define __STUDENT__

#include <string>

class Student {
    private:
    std::string studentId;

    std::string firstName;

    std::string lastName;

    std::string classId;

    double grade;

    public:
    std::string getStudentId();

    std::string getFirstName();

    std::string getLastName();

    std::string getClassId();

    double getGrade();

    void setStudentId(std::string id);

    void setFirstName(std::string fName);

    void setLastName(std::string lName);

    void setClassId(std::string cId);

    void setGrade(double g);
};

#endif // __STUDENT__
