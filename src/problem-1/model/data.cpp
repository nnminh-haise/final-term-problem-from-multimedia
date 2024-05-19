#include "data.h"

Console console;

std::string ws2s(const std::wstring wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

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
    // #ifdef _WIN32
    //     SetConsoleOutputCP(CP_UTF8);
    //     SetConsoleCP(CP_UTF8);
    // #endif
    // std::locale::global(std::locale("en_US.UTF-8"));
    Students.clear();
    checkId.clear();
    OpenXLSX::XLDocument doc;
    doc.open(path);
    OpenXLSX::XLWorksheet wks = doc.workbook().worksheet("Sheet1");
    for (unsigned int i = 2; i <= wks.rowCount(); i++)
    {
        const unsigned int index = wks.cell(i, 1).value();
        const std::string id = (wks.cell(i, 2).value().get<std::string>());
        const std::string lastName = (wks.cell(i, 3).value().get<std::string>());
        const std::string firstName = (wks.cell(i, 4).value().get<std::string>());
        const std::string classId = (wks.cell(i, 5).value().get<std::string>());
        const unsigned int grade = wks.cell(i, 6).value();
        Student *student = new Student();
        student->setIndex(index);
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

void Data::Remove(std::string path, std::string ID)
{
    if (existId(ID))
    {
        Student *student = (findStudentById(ID)[0]);
        OpenXLSX::XLDocument doc;
        doc.open(path);
        OpenXLSX::XLWorksheet wks = doc.workbook().sheet(1);
        for (int i = student->getIndex() + 1; i <= getNumberOfStudent() + 1; i++)
        {
            wks.cell((uint32_t)(i), 2).value() = wks.cell((uint32_t)(i + 1), 2).value();
            wks.cell((uint32_t)(i), 3).value() = wks.cell((uint32_t)(i + 1), 3).value();
            wks.cell((uint32_t)(i), 4).value() = wks.cell((uint32_t)(i + 1), 4).value();
            wks.cell((uint32_t)(i), 5).value() = wks.cell((uint32_t)(i + 1), 5).value();
            wks.cell((uint32_t)(i), 6).value() = wks.cell((uint32_t)(i + 1), 6).value();
        }
        wks.cell((uint32_t)(wks.rowCount()), 1).value() = "";
        refreshData(path);
    }
    else
    {
        console.printWithColor("\nData source: The student's id is not exist\n", LIGHT_RED);
    }
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

std::vector<Student *> Data::findStudentById(std::string ID)
{
    std::vector<Student *> Res;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getStudentId() == ID)
        {
            printStudent(Students[i]);
            Res.push_back(Students[i]);
            std::cout << "\t";
            Students[i]->getReverseName();
        }
    }
    return Res;
}

std::vector<Student *> Data::findStudentByLastName(std::string lastName)
{
    std::vector<Student *> Res;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getLastName() == lastName)
        {
            printStudent(Students[i]);
            Res.push_back(Students[i]);
        }
    }
    return Res;
}

std::vector<Student *> Data::findStudentbyFirstName(std::string firstName)
{
    std::vector<Student *> Res;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getFirstName() == firstName)
        {
            printStudent(Students[i]);
            Res.push_back(Students[i]);
        }
    }
    return Res;
}

std::vector<Student *> Data::findStudentbyClassId(std::string classId)
{
    std::vector<Student *> Res;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getClassId() == classId)
        {
            printStudent(Students[i]);
            Res.push_back(Students[i]);
        }
    }
    return Res;
}

std::vector<Student *> Data::findStudentbyGrade(int grade)
{
    std::vector<Student *> Res;
    for (size_t i = 0; i < getNumberOfStudent(); i++)
    {
        if (Students[i]->getGrade() == grade)
        {
            printStudent(Students[i]);
            Res.push_back(Students[i]);
        }
    }
    return Res;
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
    std::cout << student->getStudentId() << ", ";
    std::cout << student->getLastName() << ", ";
    std::cout << student->getFirstName() << ", ";
    std::cout << student->getClassId() << ", ";
    std::cout << student->getGrade();
    std::cout << "\tSize: " << student->getAllName().size();
    std::cout << std::endl;
}