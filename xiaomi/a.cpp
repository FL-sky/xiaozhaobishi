#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

template <class Type>
class ListNode
{
public:
    Type data;
    ListNode<Type> *next;
};

class Solution
{
public:
    /* Write Code Here */
    ListNode<int> *reverseBetween(ListNode<int> *head, int left, int right)
    {
        typedef ListNode<int> *lnp;
        if (left == right)
            return head;
        lnp cur = head, pre = nullptr, nxt = cur->next;
        int i = 1;
        while (i < left)
        {
            pre = cur;
            cur++;
            nxt = cur->next;
            ++i;
        }
        lnp lp = cur;
        lnp pr = pre;
        while (i < right)
        {
            cur++;
            nxt = cur->next;
            ++i;
        }
        lnp rp = cur;
        lnp ed = nxt;
        //
        if (pr)
            pr->next = rp;
        //
        pre = ed;
        cur = lp;
        while (cur != ed)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = cur->next;
        }
        if (left > 1)
            return head;
        return rp;
    }
};

int main()
{
    ListNode<int> *res = NULL;

    int head_size = 0;
    cin >> head_size;

    ListNode<int> *head = NULL, *head_curr = NULL;
    int head_item;
    for (int head_i = 0; head_i < head_size; head_i++)
    {
        cin >> head_item;

        ListNode<int> *head_temp = new ListNode<int>();
        head_temp->data = head_item;
        head_temp->next = NULL;
        if (head == NULL)
        {
            head = head_curr = head_temp;
        }
        else
        {
            head_curr->next = head_temp;
            head_curr = head_temp;
        }
    }

    int left;
    cin >> left;

    int right;
    cin >> right;

    Solution *s = new Solution();
    res = s->reverseBetween(head, left, right);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
