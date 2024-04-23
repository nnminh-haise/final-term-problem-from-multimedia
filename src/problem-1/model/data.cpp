#include "data.h"

Console console;

Data::Data(std::string path)
{
    refreshData(path);
}

size_t Data::getNumberOfStudent()
{
    return Students.size();
}

bool Data::existId(std::string id)
{
    return (checkId.find(id) != checkId.end());
}

void Data::refreshData(std::string path)
{
    Students.clear();
    checkId.clear();
    OpenXLSX::XLDocument doc;
    doc.open(path);
    OpenXLSX::XLWorksheet wks = doc.workbook().worksheet("Sheet1");
    // std::cout << "Column: " << wks.columnCount() << "\nRow: " << wks.rowCount() << std::endl;
    for (unsigned int i = 2; i <= wks.rowCount(); i++)
    {
        // const unsigned int index = wks.cell(i, 1).value(); // Index of student, we dont need it because we use index of array (hehe)
        const std::string id = (wks.cell(i, 2).value().get<std::string>());
        const std::string lastName = (wks.cell(i, 3).value().get<std::string>());
        const std::string firstName = (wks.cell(i, 4).value().get<std::string>());
        const std::string classId = (wks.cell(i, 5).value().get<std::string>());
        const unsigned int grade = wks.cell(i, 6).value();
        // std::cout << id << '\t' << lastName << '\t' << firstName << '\t' << classId << '\t' << mark << std::endl;
        Student *student = new Student();
        student->setStudentId(id);
        student->setLastName(lastName);
        student->setFirstName(firstName);
        student->setClassId(classId);
        student->setGrade(grade);
        Students.push_back(student);
        checkId[id] = true;
    }
    doc.close();
}

void Data::addData(std::string path, Student *student)
{

    if (!existId(student->getStudentId()))
    {
        OpenXLSX::XLDocument doc;
        doc.open(path);
        OpenXLSX::XLWorksheet wks = doc.workbook().sheet(1);
        wks.cell((uint32_t)getNumberOfStudent() + 2, 1).value() = getNumberOfStudent() + 1;
        wks.cell((uint32_t)getNumberOfStudent() + 2, 2).value() = student->getStudentId();
        wks.cell((uint32_t)getNumberOfStudent() + 2, 3).value() = student->getLastName();
        wks.cell((uint32_t)getNumberOfStudent() + 2, 4).value() = student->getFirstName();
        wks.cell((uint32_t)getNumberOfStudent() + 2, 5).value() = student->getClassId();
        wks.cell((uint32_t)getNumberOfStudent() + 2, 6).value() = student->getGrade();
        doc.save();
        doc.close();
        checkId[student->getStudentId()] = true;
        refreshData(path);
        console.printWithColor("\nData source: Add student to data source successfully!\n", LIGHT_GREEN);
    }
    else
    {
        console.printWithColor("\nData source: The student's id already exists!\n", LIGHT_RED);
    }
}

void Data::Remove(std::string path, Student *student)
{
    
}

std::vector<Student *> Data::getData()
{
    return Students;
}

void Data::printStudentLowerThan(int grade)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getGrade() < grade)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::printStudentHigherThan(int grade)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getGrade() >= grade)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::findStudentById(std::string ID)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getStudentId() == ID)
        {
            printStudent(Students[i]);
            // std::cout << "\t";
            // Students[i]->getReverseName();
        }
    }
}

void Data::findStudentByLastName(std::string lastName)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getLastName() == lastName)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::findStudentbyFirstName(std::string firstName)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getFirstName() == firstName)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::findStudentbyClassId(std::string classId)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getClassId() == classId)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::findStudentbyGrade(int grade)
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getGrade() == grade)
        {
            printStudent(Students[i]);
        }
    }
}

void Data::sortStudentById()
{
    /*
        example: N23DCCN204 -> [N23DCCN][204]
    */
    std::map<std::string, std::vector<std::string>> idSplit;
    std::set<std::string> idSave;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        idSplit[Students[i]->getStudentId().substr(0, 7)].push_back(Students[i]->getStudentId().substr(7, 3));
        idSave.insert(Students[i]->getStudentId().substr(0, 7));
        // std::cout << Students[i]->getStudentId().substr(0, 7) << std::endl;
    }
    for (std::set<std::string>::iterator itr = idSave.begin(); itr != idSave.end(); itr++)
    {
        BBsort(idSplit[*itr]);
        for (size_t i = 0; i < idSplit[*itr].size(); i++)
        {
            findStudentById(*itr + idSplit[*itr][i]);
        }
    }
}

void Data::sortStudentByLastName()
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        for (size_t j = i + 1; j < getNumberOfStudent(); j++)
        {
            if (Students[i]->getLastName()[0] > Students[j]->getLastName()[0])
            {
                std::swap(Students[i], Students[j]);
            }
        }
    }
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        printStudent(Students[i]);
    }
}

void Data::sortStudentbyFirstName()
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        for (size_t j = i + 1; j < getNumberOfStudent(); j++)
        {
            if (Students[i]->getFirstName()[0] > Students[j]->getFirstName()[0])
            {
                std::swap(Students[i], Students[j]);
            }
        }
    }
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        printStudent(Students[i]);
    }
}

void Data::sortStudentbyClassId()
{
    /*
        example: E23CQCE01-N -> [E23CQCE][01][-N]
    */
    std::map<std::string, std::set<std::string>> idSplit;
    std::set<std::string> classIdSave;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        idSplit[Students[i]->getClassId().substr(0, (Students[i]->getClassId().size() > 11 ? 9 : 7))].insert(Students[i]->getClassId().substr((Students[i]->getClassId().size() > 11 ? 9 : 7), 2));
        classIdSave.insert(Students[i]->getClassId().substr(0, (Students[i]->getClassId().size() > 11 ? 9 : 7)));
        // std::cout << Students[i]->getClassId().substr(0, 7) << std::endl;
    }
    for (std::set<std::string>::iterator itr = classIdSave.begin(); itr != classIdSave.end(); itr++)
    {
        for (size_t i = 0; i < idSplit[*itr].size(); i++)
        {
            for (std::set<std::string>::iterator jtr = idSplit[*itr].begin(); jtr != idSplit[*itr].end(); jtr++)
            {
                // std::cout << (*itr + *jtr + "-N") << std::endl;
                findStudentbyClassId(*itr + *jtr + "-N");
            }
        }
    }
}

void Data::sortStudentbyGrade()
{
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        for (size_t j = i + 1; j < getNumberOfStudent(); j++)
        {
            if (Students[i]->getGrade() < Students[j]->getGrade())
            {
                std::swap(Students[i], Students[j]);
            }
        }
    }
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        printStudent(Students[i]);
    }
}

void Data::printStudent(Student *student)
{
    // I use nowide to print out UTF-8 but it is not a radical solution to solve the problem string can't get UTF-8 character.
    nowide::cout << student->getStudentId() << ", ";
    nowide::cout << student->getLastName() << ", ";
    nowide::cout << student->getFirstName() << ", ";
    nowide::cout << student->getClassId() << ", ";
    nowide::cout << student->getGrade();
    nowide::cout << std::endl;
}