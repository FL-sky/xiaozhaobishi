#include <bits/stdc++.h>
using namespace std;

int ans = 100;
int pt[10];
void dfs(int a, int b, int dep)
{
    if (dep >= ans)
    {
        return;
    }
    if (a % b == 0 || b % a == 0)
    {
        ans = min(ans, dep);
        return;
    }
    string x = to_string(a);
    string y = to_string(b);
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= '0')
        {
            // string ns = x.substr(0, i);
            // ns += x.substr(i + 1, x.length() - i - 1);
            // int nx = atoi(ns.c_str());
            int nx = a % pt[i] + a / pt[i + 1] * pt[i];
            dfs(nx, b, dep + 1);
        }
    }
    for (int i = 0; i < y.length(); i++)
    {
        if (y[i] >= '0')
        {
            // string ns = y.substr(0, i);
            // ns += y.substr(i + 1, y.length() - i - 1);
            // int ny = atoi(ns.c_str());
            int ny = b % pt[i] + b / pt[i + 1] * pt[i];
            dfs(a, ny, dep + 1);
        }
    }
}
int main()
{
    pt[0] = 1;
    for (int i = 1; i < 10; i++)
        pt[i] = pt[i - 1] * 10;
    int a, b;
    cin >> a >> b;
    ans = 1e9;
    dfs(a, b, 0);
    if (ans > 99)
        ans = -1;
    cout << ans << endl;
    return 0;
}