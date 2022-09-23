#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

struct po
{
    ll mi, mx;
    bool operator<(const po &b) const
    {
        return mx < b.mx;
    }
} a[N];
struct bianjie
{
    ll l, ty;
    bool operator<(const bianjie &b) const
    {
        if (l == b.l)
        {
            return ty < b.ty;
        }
        return l < b.l;
    }
} bj[N];
int main()
{
    int n, x;
    ll ai;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        a[i].mi = ai - x;
        a[i].mx = ai + x;
        bj[i].l = ai - x;
        bj[i].ty = 0;
        bj[i + n].l = ai + x;
        bj[i + n].ty = 1;
    }
    int nl = n * 2;
    sort(bj, bj + nl);
    sort(a, a + n);
    int cnt = 0, ans = 0;
    for (int i = 0; i < nl; i++)
    {
        int ty = bj[i].ty;
        if (ty == 0)
        {
            ++cnt;
        }
        else
        {
            --cnt;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans << endl;
    return 0;
}