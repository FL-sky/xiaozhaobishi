#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int can[100000 + 10];
int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(m + 2);
    v[0] = v[m + 1] = 0;
    int mxh = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%*c%d", &v[i]);
        v[i] = -v[i];
        v[i] = max(0, v[i]);
        mxh = max(mxh, v[i]);
    }
    int ans = 0;
    memset(can, -1, sizeof(can));
    for (int h = 1; h <= mxh; h++)
    {
        int i = 1, l, r;
        while (i <= m)
        {
            int ti = i;
            if (can[ti] != -1)
            {
                i = can[ti];
            }
            while (i <= m && v[i] < h)
                ++i;
            can[ti] = max(can[ti], l);
            l = r = i;
            while (i <= m && v[i] >= h)
                ++i;
            r = i;
            int len = r - l;
            if (len >= n)
            {
                ans += len / n;
            }
            else
            {
                can[l] = r + 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}