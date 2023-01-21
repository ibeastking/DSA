#include <bits\stdc++.h>

using namespace std;

//*structure to define student with roll number,name,marks obtained
class student
{
    int n;
    char nm[15];
    double mrk;

public:
    student()
    {
        n = 0;
        nm[0] = '\0';
        mrk = 0.0;
    }

    ~student() {}

    void set(int n)
    {
        this->n = n;
        cout << "Name: ";
        cin >> nm;
        cout << "Marks: ";
        cin >> mrk;
    }

    int getNo()
    {
        return n;
    }

    double getMarks()
    {
        return mrk;
    }

    void display()
    {
        cout << "\nStudent Data\nNumber: " << n << "\nName: " << nm << "\nMarks: " << mrk;
    }
};

int main()
{
    student s;
    int n;

    int opt;
    while (1)
    {
        cout << "\nMenu\n1. Write to File\n2. Read from the File\n3. Exit\nEnter Option: ";
        cin >> opt;

        if (opt == 1)
        {
            ofstream sout;
            sout.open("data.dat", ios::binary | ios::out);

            while (1)
            {
                cout << "\nEnter Roll Number: ";
                cin >> n;

                if (n == 0)
                {
                    break;
                }

                s.set(n);
                sout.write((char *)&s, sizeof(s));
            }

            sout.close();
        }

        if (opt == 2)
        {
            ifstream sin;
            sin.open("data.dat", ios::binary | ios::in);

            while (1)
            {
                sin.read((char *)&s, sizeof(s));

                if (sin.eof())
                {
                    break;
                }

                s.display();
            }

            sin.close();
        }

        if (opt != 1 || opt != 2)
        {
            break;
        }
    }

    return 0;
}