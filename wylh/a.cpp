#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string a, b;
    cin >> n;
    int m = n;
    int sc = 0;
    while (m-- > 0)
    {
        cin >> a >> b;
        int la = a.length(), lb = b.length();
        if (a[0] == b[0])
        {
            sc += 2;
        }
        //
        string sa = a.substr(la - 5);
        string sb = b.substr(lb - 5);

        int tp = 0, mx = 0;
        for (int i = 0; i < 5; i++)
        {
            if (sa[i] == sb[i])
            {
                ++tp;
            }
            else
            {
                mx = max(mx, tp);
                tp = 0;
            }
        }
        mx = max(mx, tp);
        sc += mx;
        //
        sa = sa.substr(1, la - 5);
        sb = sb.substr(1, lb - 5);
        sc += (sa == sb) * 3;
    }
    printf("%.2f\n", sc / 10.0);
    return 0;
}