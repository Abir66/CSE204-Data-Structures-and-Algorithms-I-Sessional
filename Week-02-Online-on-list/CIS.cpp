#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

struct Student
{
    int x, y;
    Student() {}
    Student(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Student &s){
        return x==s.x && y==s.y;
    }
};

void printStudents(List<Student> &students)
{
    for (students.moveToStart();;students.next())
    {
        std::cout << "[" << students.getValue().x << "," << students.getValue().y << "]";
        if (students.currPos() == students.length() - 1) break;
    }
    std::cout<<std::endl;
    students.moveToStart();
}

void insertStudent(List<Student> &students, const Student &s)
{

    if (students.length()!=0 && (students.getValue().x == s.x || students.getValue().y == s.y))
    {
        std::cout << "duplicate" << std::endl;
        students.duplicate();
        printStudents(students);

        std::cout << "update" << std::endl;
        students.update(s);
        printStudents(students);    
    }
    else
    {
        std::cout << "insert" << std::endl;
        students.insert(s);
        printStudents(students);
    }
}

int main()
{
    int x, y;
    LinkedList<Student> students;
    while (true)
    {
        std::cin >> x >> y;
        if(x==0 || y==0) break;
        insertStudent(students, Student(x,y));
    }

    return 0;
}