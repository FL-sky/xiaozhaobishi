#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int main()
{
    string str;
    cin >> str;
    int pos = str.find(",");
    string yuan = str.substr(0, pos);
    string zi = str.substr(pos + 1);
    pos = yuan.find(zi);
    string a = yuan.substr(0, pos);
    string b = yuan.substr(pos + zi.length());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << b << zi << a << endl;
    return 0;
}