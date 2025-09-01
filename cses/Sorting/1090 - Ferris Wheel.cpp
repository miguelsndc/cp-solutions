#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vi p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    vb taken(n, false);
    int i = 0;
    int j = n - 1;
    int ans = 0;
    while (i < j) {
        if (p[i] + p[j] > x) {
            j--;
        } else {
            ans++;
            taken[i] = taken[j] = true;
            i++;
            j--;
        }
    }
    ans += count(taken.begin(), taken.end(), false);  // kids unpaired
    cout << ans;
    return 0;
}