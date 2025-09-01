#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a; cin >> a;
    string x = "bbaa";
    string result;
    
    if (a < 4) {
        result = x.substr(0, a);
    } else {
        int n = a / 4;
        int m = a % 4;

        for (int i = 0; i < n; i++) {
            result += x;
        }

        result += x.substr(0, m);
    }

    cout << result;
}