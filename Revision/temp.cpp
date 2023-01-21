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
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    swap(&arr[i], &arr[j]);
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
        int i, j, val;

        for (i = 1; i < n; i++)
        {
            val = arr[i];
            for (j = i - 1; j > -1; j--)
            {
                if (val < arr[j])
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
        for (i = 0; i < n; i++)
        {
            for (j = k = i; j < n; j++)
            {
                if (arr[j] < arr[i])
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
            } while (pivot >= arr[i]);

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

int main()
{
    int size;
    cout << "\nEnter the size: ";
    cin >> size;

    int arr[size];

    Bubble<int> b;
    b.input(arr, size);
    b.display(arr, size);
    b.Quick(arr, 0, size - 1);
    b.display(arr, size);

    return 0;
}