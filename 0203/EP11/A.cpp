#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

float area(int x2, int x3) {
    return 0.5 * (x3 - x2);
}

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    set<float> areas;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            areas.insert(area(x[i], x[j]));
        }
    }
    cout << areas.size() << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}