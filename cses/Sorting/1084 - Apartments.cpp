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

void solve() {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // 45 60 60 80
    // 30 60 75
    int count = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (b[j] <= a[i] + k && b[j] >= a[i] - k) {
            count++;
            j++, i++;
        } else if (a[i] - k > b[j]) {
            j++;
        } else {
            i++;
        }
    }

    cout << count;

    return 0;
}