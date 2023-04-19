#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p)
{
    return os << '<' << p.first << "|" << p.second << '>';
}

template <typename T>
string to_string(T container, char ch)
{
    stringstream sstr;
    auto cont_it = container.begin();
    
    for (; cont_it != --container.end(); ++cont_it)
        sstr << *cont_it << ch << ' ';
    sstr << *cont_it;
 
    return sstr.str();
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> m)
{
    return os << '{' << to_string(m, ';') << '}' << endl;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
    return os << '[' << to_string(v, ',') << ']' << endl;
}

int main()
{
    vector<int> v = {1, 3, 435, 345};
    cout << v;

    map<string, int> m = {{"A", 1}, {"B", 2}, {"C", 3}};
    cout << m;

    return 0;
}
