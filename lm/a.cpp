#include <bits/stdc++.h> //RE
using namespace std;

const int N = 1e6 + 6;
int a[N];
struct po
{
    int val, id;
};
int main()
{
    int n, fst, k;
    if (scanf("%d,%d,%d", &n, &fst, &k) != 3)
    {
        puts("-1");
        return 0;
    }
    if (fst > n || fst < 1 || k <= 0)
    {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (scanf(",%d", &a[i]) != 1)
        {
            puts("-1");
            return 0;
        }
    }
    list<po> lt;
    for (int i = 0; i < n; i++)
    {
        lt.push_back({a[i], i + 1});
    }
    auto it = lt.begin();
    int i = 0;
    for (; it != lt.end(); it++)
    {
        if (++i == fst)
        {
            break;
        }
    }
    //
    while (lt.size() > 1)
    {
        i = 0;
        for (;; it++)
        {
            if (it == lt.end())
            {
                it = lt.begin();
            }
            if (++i == k)
            {
                break;
            }
        }
        //
        auto ij = it;
        auto tv = *it;
        ++ij;
        lt.erase(it);
        k = tv.val;
        k = k % lt.size();
        if (k == 0)
        {
            k = lt.size();
        }
        it = ij;
        if (it == lt.end())
        {
            it = lt.begin();
        }
    }
    cout << lt.begin()->id << endl;
    return 0;
}