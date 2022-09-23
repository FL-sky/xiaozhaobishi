#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
void dfs(int u)
{
    if (2 * u + 1 < n)
        dfs(2 * u + 1);
    printf("%d ", v[u]);
    if (2 * u + 2 < n)
        dfs(2 * u + 2);
}
void dfs2(int u)
{
    if (2 * u + 2 < n)
        dfs2(2 * u + 2);
    printf("%d ", v[u]);
    if (2 * u + 1 < n)
        dfs2(2 * u + 1);
}
int main()
{
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    n = v.size();
    if (n > 0)
    {
        dfs(0);
        dfs2(0);
    }
    return 0;
}