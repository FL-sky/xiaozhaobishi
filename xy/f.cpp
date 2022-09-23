#include <bits/stdc++.h>
using namespace std;
// nowcoder for 1e9 430ms
const int N = 1e5 + 5;
char s[N];
struct po
{
    int v, cnt;
};
int main()
{
    cin >> s;
    int l = strlen(s);
    list<po> lt;
    for (int i = 0; i < l; i++)
    {
        int c = 1;
        int j = i;
        while (j < l && s[i] == s[j])
        {
            ++j;
        }
        lt.push_back({s[i], j - i});
    }
    return 0;
}