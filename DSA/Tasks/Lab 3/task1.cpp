#include <iostream>
using namespace std;
class Student
{
private:
    string Name;
    int rollNumber;
    string uniName;
    string className;

public:
    Student() {
        cout << "Default Constructor" << endl;
        Name = "null";
        rollNumber = 0;
        uniName = "null";
        className = "null";
    }

    Student(string Name, int rollNumber, string uniName, string className) {
        cout << "Parameterized Constructor" << endl;
        this->Name = Name;
        this->rollNumber = rollNumber;
        this->uniName = uniName;
        this->className = className;
    }

    Student(Student &student) {
        cout << "Copy Constructor" << endl;
        Name = student.Name;
        rollNumber = student.rollNumber;
        uniName = student.uniName;
        className = student.className;
    }

    void displayStudentDetail()
    {
        cout << "\nStudent information";
        cout << "\nName = " << Name;
        cout << "\nUniversity Name = " << uniName;
        cout << "\nRoll Number = " << rollNumber;
        cout << "\nClass Name = " << className;
        cout<<"\n<----------------------------------->\n";
    }
};

int main()
{
    Student studentFirst;
    Student studentSecond("Hanzla Ahmad", 61002, "Riphah International University Of Lahore", "Bachelor Of Sciences In Computer Science");
    Student copyStudent(studentSecond);

    studentFirst.displayStudentDetail();
    studentSecond.displayStudentDetail();
    copyStudent.displayStudentDetail();
}