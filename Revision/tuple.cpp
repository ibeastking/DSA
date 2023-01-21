#include <bits\stdc++.h>
using namespace std;

tuple<int, float, string> fun()
{
    int a;
    float b;
    string c;

    cout << "\nEnter the values: ";
    cin >> a >> b >> c;

    return make_tuple(a, b, c);
}

int main()
{
    vector<tuple<int, float, string>> v;

    for (int i = 0; i < 5; i++)
    {
        tuple<int, float, string> tp;
        tp = fun();
        v.push_back(tp);
    }

    for (int i = 0; i < 5; i++)
    {
        tuple<int, float, string> t;
        t = v.at(i);
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }

    return 0;
}