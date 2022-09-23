#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;
int gt(int rx)
{
    int x = rx;
    int rt = 0;
    while (x)
    {
        rt += x % 10;
        x /= 10;
    }
    if (rt == 31)
    {
        cout << rx << "  ";
    }
    return rt;
}
int a[20000];
map<int, int> st;
int main()
{
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            st[153 * i + 500 * j] = 1;
        }
    }
    cout << st[75845] << endl;
    cout << st[75846] << endl;
    cout << st[75847] << endl;
    cout << st[75848] << endl;
    return 0;
}