#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class student
{
    public:
        int age;
        string name;
        student(int age_, string name_)
        {
            age = age_;
            name = name_;
        }
        student operator+(student s2)
        {
            student s1;
            s1.name = name + s2.name;
            s1.age = age + s2.age;

            return s1;
        }   
};

ostream& operator<<(ostream& os, student s)
{
    os << s.name << " " << s.age << endl;

    return os;
}

int main()
{
    student vitek = {1, "vitia"};
    student ivan = {2, "ivan"};

    vitek = vitek + ivan;
    cout << vitek << ivan;

    return 0;
}
