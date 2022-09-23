#include <bits/stdc++.h>
using namespace std;
// nowcoder for 1e9 430ms
const int N = 1e5 + 5;
char s[N];
int main()
{
    cin >> s;
    int l = strlen(s);
    int i = l - 3;
    long long ans = 0;
    while (1)
    {

        while (i >= 0)
        {
            if (s[i] == s[i + 1] && s[i + 1] != s[i + 2])
            {
                break;
            }
            --i;
        }
        if (i < 0)
        {
            break;
        }
        int p = i;
        char ch = s[p];
        s[p] = s[p + 1] = s[p + 2] = ch;
        int r = l - p - 2;
        ans += r;
        --i;
    }
    cout << ans << endl;
    return 0;
}