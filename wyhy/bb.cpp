#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int mix, miy, mxx, mxy;
struct po
{
    int x0, y0, x1, y1;
    void input()
    {
        cin >> x0 >> y0 >> x1 >> y1;
        ++x0, ++y0, ++x1, ++y1;
        mix = min(mix, x0);
        miy = min(miy, y0);
        mxx = max(mxx, x1);
        mxy = max(mxy, y1);
    }
    bool operator<(const po &b) const
    {
        return vector<int>{x0, y0, x1, y1} < vector<int>{b.x0, b.y0, b.x1, b.y1};
    }
} arr[N];
int flg[N];
bool isi(const po a, const po b)
{
    int fg = 0;
    fg = (b.x0 >= a.x0 && b.x0 <= a.x1 && b.y0 >= a.y0 && b.y0 <= a.y1);
    if (fg == 1)
        fg += (b.x1 >= a.x0 && b.x1 <= a.x1 && b.y0 >= a.y0 && b.y0 <= a.y1);
    if (fg == 2)
        fg += (b.x0 >= a.x0 && b.x0 <= a.x1 && b.y1 >= a.y0 && b.y1 <= a.y1);
    if (fg == 3)
        fg += (b.x1 >= a.x0 && b.x1 <= a.x1 && b.y1 >= a.y0 && b.y1 <= a.y1);
    return fg == 4;
}
bool isin(const po a, const po b)
{
    if (isi(a, b))
        return true;
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
int lowbit(int x)
{
    return x & -x;
}
struct Event
{
    int x, y1, y2;
    int add;
    bool operator<(const Event &b) const
    {
        return x < b.x;
    }
};
struct IntervalTreeNode
{
    int count, total;
};
int n;
Event evt[M * 2 + 1];
IntervalTreeNode tree[M * 2 + 1];
int id[M * 2];
void up(int i, int lb, int rb)
{
    tree[i].total = tree[i << 1].total + tree[i << 1 | 1].total;
    if (tree[i].count)
        tree[i].total = id[rb] - id[lb];
}
void ins(int i, int lb, int rb, int a, int b, int k)
{
    if (a == lb && b == rb)
    {
        tree[i].count += k;
        up(i, lb, rb);
        return;
    }
    int med = (lb + rb) >> 1;
    if (b <= med)
    {
        ins(i << 1, lb, med, a, b, k);
    }
    else if (a >= med)
    {
        ins(i << 1 | 1, med, rb, a, b, k);
    }
    else
    {
        ins(i << 1, lb, med, a, med, k);
        ins(i << 1 | 1, med, rb, med, b, k);
    }
    up(i, lb, rb);
}

int area()
{
    for (int i = 0; i < n; i++)
    {
        id[i] = arr[i].y0;
        id[i + n] = arr[i].y1;
    }
    sort(id, id + 2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        arr[i].y0 = lower_bound(id, id + 2 * n, arr[i].y0) - id;
        arr[i].y1 = lower_bound(id, id + 2 * n, arr[i].y1) - id;
    }
    for (int i = 0; i < n; i++)
    {
        evt[i].add = 1;
        evt[i + n].add = -1;
        evt[i].x = arr[i].x0;
        evt[i + n].x = arr[i].x1;
        evt[i].y1 = evt[i + n].y1 = arr[i].y0;
        evt[i].y2 = evt[i + n].y2 = arr[i].y1;
    }
    sort(evt, evt + 2 * n);
    long long ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i > 0 && evt[i].x > evt[i - 1].x)
        {
            ans += (evt[i].x - evt[i - 1].x) * (tree[1].total);
        }
        ins(1, 0, 2 * n - 1, evt[i].y1, evt[i].y2, evt[i].add);
    }
    return ans;
}
void init()
{
    memset(flg, 0, sizeof(flg));
    memset(tree, 0, sizeof(tree));
    memset(id, 0, sizeof(id));
    memset(evt, 0, sizeof(evt));
}
int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        init();
        // int n;
        cin >> n;
        mix = miy = 1e9;
        mxx = mxy = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i].input();
        }
        sort(arr, arr + n);
        memset(flg, 0, sizeof(flg));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isin(arr[i], arr[j]))
                {
                    flg[i] = flg[j] = 1;
                }
            }
        }
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (flg[i])
            {
                arr[len++] = arr[i];
            }
        }
        n = len;
        cout << area() << endl;
    }
    return 0;
}