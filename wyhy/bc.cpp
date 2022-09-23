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
int lowbit(int x)
{
    return x & -x;
}
int add[M << 2];
int sum[M << 2], x[M << 2];
struct node
{
    int cnt;
    int l, r, h;
    // node() {}
    node(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        l = a;
        r = b;
        h = c;
        cnt = d;
    }
    bool operator<(const node &b) const
    {
        return h < b.h;
    }
} s[M << 2];
void pushup(int rt, int l, int r)
{
    if (add[rt])
    {
        sum[rt] = x[r + 1] - x[l];
    }
    else if (l == r)
    {
        sum[rt] = 0;
    }
    else
    {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
}
void update(int rt, int l, int r, int L, int R, int c)
{
    if (L <= l && r <= R)
    {
        add[rt] += c;
        pushup(rt, l, r);
        return;
    }
    int mid = (l + r) / 2;
    if (L <= mid)
    {
        update(rt << 1, l, mid, L, R, c);
    }
    if (R > mid)
    {
        update(rt << 1 | 1, mid + 1, r, L, R, c);
    }
    pushup(rt, l, r);
}

int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        cin >> n;
        mix = miy = 1e9;
        mxx = mxy = 0;
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
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (flg[i])
            {
                po &u = a[i];
                int a = u.x0, b = u.x1, c = u.y0, d = u.y1;
                x[len] = a;
                s[len++] = node(a, c, b, 1);
                x[len] = c;
                s[len++] = node(a, c, d, -1);
            }
        }
        sort(x, x + len);
        sort(s, s + len);
        memset(add, 0, sizeof(add));
        memset(sum, 0, sizeof(sum));
        set<int> st;
        for (int i = 0; i < len; i++)
        {
            st.insert(x[i]);
        }
        int lx = 0;
        for (auto it : st)
        {
            x[lx++] = it;
        }
        int ans = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int l = lower_bound(x, x + lx, s[i].l) - x;
            int r = lower_bound(x, x + lx, s[i].r) - x - 1;
            if (l > r)
                continue;
            update(1, 0, lx - 1, l, r, s[i].cnt);
            ans += sum[1] * (s[i + 1].h - s[i].h);
        }
        cout << ans << endl;
    }
    return 0;
}