#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    int x = 0, y = 0;
    while (ch = getchar())
    {
        if (ch == 'L')
            --x;
        else if (ch == 'R')
            ++x;
        else if (ch == 'U')
            ++y;
        else if (ch == 'D')
            --y;
    }
    printf("(%d,%d)", x, y);
    return 0;
}