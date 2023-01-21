#include <bits\stdc++.h>
using namespace std;

//* declaring the data
typedef struct da
{
    int roll;
    char nm[50];
    double marks;
} d;

//* declaring the node
typedef struct NODE
{
    d data;
    struct NODE *right;
    struct NODE *left;
} node;

class bst
{
public:
    node *root;

    bst()
    {
        node *root = NULL;
    }

    node *createnode(int d)
    {
        node *a;
        a = new node();
        (a->data).roll = d;

        cout << "\nEnter Name: ";
        cin >> (a->data).nm;
        cout << "\nEnter marks: ";
        cin >> (a->data).marks;

        a->right = a->left = NULL;
        return a;
    }

    void createtree()
    {
        int d;

        while (1)
        {
            if (root == NULL)
            {
                cout << "\nEnter Node Data: ";
                cin >> d;
                root = createnode(d);
            }

            else
            {
                cout << "Enter Node Data: ";
                cin >> d;

                if (d <= 0)
                {
                    return;
                }
                else
                {
                    node *a, *b;
                    a = createnode(d);
                    b = root;

                    while (1)
                    {
                        if ((b->data).roll > (a->data).roll)
                        {
                            if (b->left == NULL)
                            {
                                b->left = a;
                                break;
                            }
                            else
                            {
                                b = b->left;
                            }
                        }
                        else
                        {
                            if (b->right == NULL)
                            {
                                b->right = a;
                                break;
                            }
                            else
                            {
                                b = b->right;
                            }
                        }
                    }
                }
            }
        }
    }

    void inorder(node *t)
    {
        if (t != NULL)
        {
            inorder(t->left);
            cout << "Roll Number: " << (t->data).roll << "\nName: " << (t->data).nm << "\nMarks: " << (t->data).marks;
            inorder(t->right);
        }
        else
        {
            return;
        }
    }
};

int main()
{
    bst a;
    a.createtree();
    a.inorder(a.root);

    return 0;
}