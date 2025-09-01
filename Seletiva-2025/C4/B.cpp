#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> gt, lt;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a > b) {
            gt.push_back(i + 1);
        } else {
            lt.push_back(i + 1);
        }
    }

    cout << "YES\n";
    if (gt.size() > lt.size()) {
        cout << gt.size() << '\n';
        for (auto c: gt) cout << c << ' ';
    } else {
        cout << lt.size() << '\n';
        for (auto c: lt) cout << c << ' ';
    }
}