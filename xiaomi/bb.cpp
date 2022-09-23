#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main()
{
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    n = v.size();
    sort(v.begin(), v.end());
    if (n <= 0)
        return 0;
    printf("%d", v[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        printf(" %d", v[i]);
    }
    return 0;
}