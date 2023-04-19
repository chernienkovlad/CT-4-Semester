#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, vector<string> v)
{
    for (auto word : v)
        os << word << endl;

    return os;
}

void split_words(vector<string>& v, string str);

int main()
{
    string str = "hello world !";
    vector<string> v;

    split_words(v, str);
    cout << v;

    return 0;
}

void split_words(vector<string>& v, string str)
{
    string::iterator w_begin = str.begin();
    string::iterator w_end = str.begin();

    while (w_end != str.end())
    {
        for (; *w_end != ' ' && w_end != str.end(); ++w_end);
        if (w_end != str.end())
        {
            v.push_back(str.substr(w_begin-str.begin(), w_end-w_begin));
            w_begin = ++w_end;
        }
        else
        {
            v.push_back(str.substr(w_begin-str.begin(), w_end-w_begin+1));
        }
    }
}
