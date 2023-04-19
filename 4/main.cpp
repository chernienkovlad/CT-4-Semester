#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

// template <typename T1, typename T2>
// class my_pair
// {
//     public:
//         T1 first;
//         T2 second;
// };

// template <typename T>
// T power(T a)
// {
//     return (a * a);
// }

// template <typename T>
// void func(T a)
// {
//     cout << "kaban" << a << endl;
// }

// template <class /*typename?*/ foo, typename T>
// void f(foo f_, T param)
// {
//     cout << "my name is ";
//     f_(47);
// }

int main()
{
    // int y = 2;
    // int x = power(y);

    // pair<string, int> p;
    // p.first = "David";
    // p.second = 1;
    // cout << p.first << ' ' << p.second << endl;

    // my_pair<string, int> p;
    // p.first = "David";
    // p.second = 1;
    // cout << p.first << ' ' << p.second << endl;

    // f(func<int>, 1);

    stringstream sstr;
    sstr << "kaban ";
    sstr << "is eating";
    string s = sstr.str();
    cout << s << endl;

    return 0;
}
