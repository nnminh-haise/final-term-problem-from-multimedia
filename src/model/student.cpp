#include "student.h"

std::string Student::getStudentId() {
    return this->studentId;
}

std::string Student::getFirstName() {
    return this->firstName;
}

std::string Student::getLastName() {
    return this->lastName;
}

std::string Student::getClassId() {
    return this->classId;
}

double Student::getGrade() {
    return this->grade;
}

void Student::setStudentId(std::string studentId) {
    this->studentId = studentId;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setClassId(std::string classId) {
    this->classId = classId;
}

void Student::setGrade(double grade) {
    this->grade = grade;
}