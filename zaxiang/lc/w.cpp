#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 10;
int main()
{
    char s[N];
    cin >> s;
    int n = strlen(s);
    int bu = n % 3;
    if (bu)
    {
        bu = 3 - bu;
    }
    char b[N];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)
    {
        int x = s[i];
        if (x >= '0' && x <= '9')
        {
            x -= '0';
        }
        else if (x >= 'a' && x <= 'z')
        {
            x = x - 'a' + 10;
        }
        else if (x >= 'A' && x <= 'Z')
        {
            x = x - 'A' + 10;
        }
        b[i] = x;
    }
    // bool *p = new bool[n * 8];
    // memcpy(p, b, sizeof(b[0]) * n);
    // for (int i = 0; i < n * 8; i++)
    //     printf("%d", p[i]);
    int p[N * 8], lp = 0;
    for (int i = 0; i < n; i++)
    {
        int x = b[i];
        vector<int> v;
        for (int j = 0; j < 8; j++)
        {
            v.push_back(x & 1);
            x = x / 2;
        }
        while (v.size())
        {
            p[lp++] = *v.rbegin();
            v.pop_back();
        }
    }
    if (bu)
    {
        int y = bu * 8;
        while (y-- > 0)
        {
            p[lp++] = -1;
        }
    }
    for (int i = 0; i < lp; i += 6)
    {
        bool flg = false;
        if (p[i] == -1)
        {
            putchar('=');
            continue;
        }
        int rt = 0;
        for (int j = 0; j < 6; j++)
        {
            int x = p[i + j];
            if (x < 0)
            {
                x = 0;
                flg = true;
            }
            rt = rt * 2 + x;
        }
        if (flg && rt == 0)
        {
            putchar('=');
        }
        else if (rt >= 0 && rt <= 25)
        {
            putchar(rt + 'A');
        }
        else if (rt <= 51)
        {
            putchar(rt - 26 + 'a');
        }
        else if (rt <= 61)
        {
            putchar(rt - 52 + '0');
        }
        else if (rt == 62)
        {
            putchar('+');
        }
        else if (rt == 63)
        {
            putchar('/');
        }
    }
    return 0;
}