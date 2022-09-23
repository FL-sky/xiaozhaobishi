#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10, M = 100 + 10;
char str[N], hx[M];
vector<int> v[128];
struct po
{
    int l, r;
};
vector<po> vp;
bool vis[N][N];
int ans = 0, ls;
void dfs(int x, int y)
{
    if (x < 0 || y >= ls)
        return;
    if (!vis[x][y])
    {
        ans++;
    }
    vis[x][y] = 1;
    if (!vis[x - 1][y])
        dfs(x - 1, y);
    if (!vis[x][y + 1])
        dfs(x, y + 1);
}
int main()
{
    scanf("%s%s", str, hx);
    ls = strlen(str);
    int lh = strlen(hx);
    for (int i = 0; i < ls; i++)
    {
        v[str[i]].push_back(i);
    }
    for (int i = 0; i < ls; i++)
    {
        if (str[i] != hx[0])
            continue;
        int ti = i + 1, j = 1;
        for (; j < lh;)
        {
            while (ti < ls && str[ti] != hx[j])
                ti++;
            if (str[ti] == hx[j])
            {
                ti++, j++;
            }
            if (ti >= ls)
                break;
        }
        if (j >= lh)
        {
            // vp.push_back({i, ti - 1});
            dfs(i, ti - 1);
        }
    }
    cout << ans << endl;
    return 0;
}