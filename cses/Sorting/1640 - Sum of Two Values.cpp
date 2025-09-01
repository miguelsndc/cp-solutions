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

// two values where the sum is x, may be several solutions
// we can sort the array and do two pointers
// if i + j == sum we are done
// if j passed i then no solutions

void solve(int n, int sum) {
    vector<pii> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i].f;
        l[i].s = i + 1;
    }
    sort(l.begin(), l.end());
    int i = 0;
    int j = n - 1;
    int found = false;
    while (i < j) {
        int s = l[i].f + l[j].f;
        if (s == sum) {
            cout << l[i].s << ' ' << l[j].s;
            found = true;
            break;
        } else if (s < sum) {
            i++;
        } else {
            j--;
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    solve(n, x);
    return 0;
}