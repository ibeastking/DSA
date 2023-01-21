#include <bits\stdc++.h>
using namespace std;

template <class om>
class Bubble
{
public:
    void input(om arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Data: ";
            cin >> arr[i];
        }
    }

    void display(om arr[], int n)
    {
        cout << "\nData: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void swap(om *a, om *b)
    {
        om temp = *a;
        *a = *b;
        *b = temp;
    }

    void bubble(om arr[], int n)
    {
        int flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            flag = 0;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                break;
            }
        }
    }

    void insertion(om arr[], int n)
    {
        int val;

        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            val = arr[i];

            for (j = i - 1; j > -1; j--)
            {
                if (arr[j] > val)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j + 1] = val;
        }
    }

    void selection(om arr[], int n)
    {
        int i, j, k;

        for (int i = 0; i < n - 1; i++)
        {
            for (j = k = i; j < n; j++)
            {
                if (arr[k] > arr[j])
                {
                    k = j;
                }
            }
            swap(&arr[i], &arr[k]);
        }
    }

    int partition(om arr[], int l, int r)
    {
        om pivot;

        if (arr[l] > arr[r])
        {
            swap(&arr[l], &arr[r]);
        }

        pivot = arr[l];
        int i = l, j = r;

        do
        {
            do
            {
                i++;
            } while (pivot > arr[i]);

            do
            {
                j--;
            } while (pivot < arr[j]);

            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
        } while (i < j);

        swap(&arr[l], &arr[j]);
        cout << endl
             << arr[l] << endl;

        return j;
    }

    void Quick(om arr[], int l, int r)
    {
        int pos;

        if (l < r)
        {
            pos = partition(arr, l, r);
            Quick(arr, l, pos);
            Quick(arr, pos + 1, r);
        }
    }
};

class Data
{
public:
    void Integer(int size)
    {
        Bubble<int> bi;
        int arr[size];
        bi.input(arr, size);
        bi.display(arr, size);
        bi.Quick(arr, 0, size - 1);
        bi.display(arr, size);
    }

    void Character(int size)
    {
        Bubble<char> bc;
        char arrc[size];
        bc.input(arrc, size);
        bc.display(arrc, size);
        bc.bubble(arrc, size);
        bc.display(arrc, size);
    }

    void Float(int size)
    {
        Bubble<float> bf;
        float arrf[size];
        bf.input(arrf, size);
        bf.display(arrf, size);
        bf.bubble(arrf, size);
        bf.display(arrf, size);
    }
};

int main()
{

    Data d;

    int size;
    cout << "\nEnter the size: ";
    cin >> size;

    while (1)
    {
        cout << "\nMenu\n1. Integer\n2. Character\n3. Float\n4. Exit\nEnter Option: ";
        int opt;
        cin >> opt;

        if (opt > 3)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            d.Integer(size);
            break;
        case 2:
            d.Character(size);
            break;
        case 3:
            d.Float(size);
            break;
        }
    }

    return 0;
}