#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
struct po
{
    int x0, y0, x1, y1;
    void input()
    {
        cin >> x0 >> y0 >> x1 >> y1;
    }
    bool operator<(const po &b) const
    {
        return vector<int>{x0, y0, x1, y1} < vector<int>{b.x0, b.y0, b.x1, b.y1};
    }
} a[N];
int flg[N];
bool isin(po &a, po &b)
{
    if (b.x0 > a.x0 && b.x0 < a.x1 && b.y0 > a.y0 && b.y0 < a.y1)
        return true; // x0,y0
    if (b.x1 > a.x0 && b.x1 < a.x1 && b.y0 > a.y0 && b.y0 < a.y1)
        return true; // x1,y0
    if (b.x0 > a.x0 && b.x0 < a.x1 && b.y1 > a.y0 && b.y1 < a.y1)
        return true; // x0,y1
    if (b.x1 > a.x0 && b.x1 < a.x1 && b.y1 > a.y0 && b.y1 < a.y1)
        return true; // x1,y1
    return false;
}

const int M = 1000 + 10;
int c[M][M];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int y, int v = 1)
{
    for (int i = x; i < M; i += lowbit(i))
    {
        for (int j = y; j < M; j += lowbit(j))
        {
            c[i][j] += v;
        }
    }
}
int sum(int x, int y)
{
    int s = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        for (int j = y; j; j -= lowbit(j))
        {
            s += c[i][j];
            if (s)
            {
                return 1;
            }
        }
    }
    return s;
}
int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            a[i].input();
        }
        sort(a, a + n);
        memset(flg, 0, sizeof(flg));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isin(a[i], a[j]))
                {
                    flg[i] = flg[j] = 1;
                }
            }
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
        {
            if (flg[i])
            {
                po &u = a[i];
                int x0 = u.x0, x1 = u.x1, y0 = u.y0, y1 = u.y1;
                x0++, y0++;
                add(x0, y0);
                add(x1 + 1, y1 + 1);
                add(x0, y1 + 1, -1);
                add(x1 + 1, y0, -1);
            }
        }
        int ret = 0;
        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                if (sum(i, j))
                {
                    ret++;
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}