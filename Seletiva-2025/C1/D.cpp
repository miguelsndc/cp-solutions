#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define loop(x, s, n) for(int x = s; x < n; x++)
#define loopincl(x, s, n) for(int x = s; x <= n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> cell(n);
    loop(i, 0, n) cin >> cell[i];
    vi psrow(n);
    vi pscol(n);
    loop(i, 0, n) {
        loop(j, 0, n) {
            if (cell[i][j] == 'o') {
                psrow[i]++; pscol[j]++;
            }
        }
    }
    ll count = 0;
    loop(i, 0, n) {
        loop(j, 0, n) {
            if (cell[i][j] == 'o') {
                count += (psrow[i] - 1) * (pscol[j] - 1);
            }
        }
    }
    cout << count;
}