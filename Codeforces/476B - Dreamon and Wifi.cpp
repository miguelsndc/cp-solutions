#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

vi fact(11); int cnt = 0, ok = 0, pb = 0;
void f(string &s, int i, int pa){
    if (i == s.size()) {
        cnt++, ok += (pa == pb); 
        return;
    }
    if (s[i] == '+') f(s, i + 1, pa + 1);
    else if (s[i] == '-') f(s, i + 1, pa - 1);
    else {
        f(s, i + 1, pa + 1); f(s, i + 1, pa - 1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while(tc--) {
        // length of both strings  <= 10
        // can do factorial 3628800
        // probabilidade = amnt ev / amnt total
        string a, b; cin >> a >> b;
        fact[0] = 1;
        rep(i, 1, 11) fact[i] = i * fact[i - 1];
        for (char c: a) {
            if (c == '+') pb++;
            else pb--;
        }
        f(b, 0, 0);
        double prob = 1.0 * ok / cnt;
        cout << setprecision(12) << fixed << prob;
    }
}