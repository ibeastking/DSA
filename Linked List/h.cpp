
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *a = list1;
        ListNode *b = list2;
        ListNode *c;
        ListNode *d;
        ListNode *head = new ListNode();

        while (a != NULL && b != NULL)
        {
            if (a->val > b->val)
            {
                c = new ListNode(b->val);
                b = b->next;
            }
            else
            {
                c = new ListNode(a->val);
                a = a->next;
            }

            if (head->next == NULL)
            {
                head->next = c;
            }
            else
            {
                d->next = c;
            }
            d = c;
        }

        while (a != NULL)
        {
            c = new ListNode(b->val);
            d->next = c;
            d = c;
            a = a->next;
        }

        while (b != NULL)
        {
            c = new ListNode(a->val);
            d->next = c;
            d = c;
            b = b->next;
        }

        return head->next;
    }
};