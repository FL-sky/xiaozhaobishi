#include <bits/stdc++.h>
using namespace std;
// nowcoder for 1e9 430ms
const int N = 1e5 + 5;
char s[N];
int main()
{
    cin >> s;
    // string tp = "sssdddccaabbcdaddddacda";
    // if (s == tp)
    // {
    //     cout << 79 << endl;
    //     return 0;
    // }
    int l = strlen(s);
    int i = l - 3;
    int p = -1;
    while (i >= 0)
    {
        if (s[i] == s[i + 1] && s[i + 1] != s[i + 2])
        {
            p = i;
            break;
        }
        --i;
    }
    if (p < 0)
    {
        puts("0");
        return 0;
    }
    long long ans = 0;
    while (1)
    {
        char ch = s[p];
        s[p] = s[p + 1] = s[p + 2] = ch;
        int r = l - p - 2;
        ans += r;
        //
        i = p - 1;
        p = -1;
        while (i >= 0)
        {
            if (s[i] == s[i + 1] && s[i + 1] != s[i + 2])
            {
                p = i;
                break;
            }
            --i;
        }
        if (p < 0)
        {
            break;
        }
        //
    }
    cout << ans << endl;
    return 0;
}