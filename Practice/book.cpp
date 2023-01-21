#include <iostream>
#include <list>
using namespace std;

void display(list<int> &l)
{
    list<int>::iterator p;

    for (p = l.begin(); p != l.end(); p++)
    {
        cout << *p;
    }
}

int main()
{
    list<int> l1;

    l1.push_back(5);
    l1.push_back(10);
    display(l1);

    return 0;
}
