#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt; 
    while(tt--) {
        int n; cin >> n;
        vector<pair<int ,int>> a(n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            p[i] = i;
        }
        // sorta y crescente
        sort(p.begin(), p.end(), [&](int v1, int v2) {
            return a[v1].second < a[v2].second;
        });

        // os menores y recebem 1
        vector<int> tp(n);
        for (int i = 0; i < n/2; i++) {
            tp[p[i]] += 1;
        }
        // sorta x crescente
        sort(p.begin(), p.end(), [&](int v1, int v2) {
            return a[v1].first < a[v2].first;
        });

        // os menores x recebem 2
        for (int i = 0; i < n/2; i++) {
            tp[p[i]] += 2;
        }

        /*
        0 nao esta nos menores x nem menores y
        1 esta entre os menores em y apenas
        2 esta entre os menores em x apenas
        3 esta entre os menores em x e em y 

        agrupa 0 e 3
        1 e 2 
        */

        // agrupa ?
        vector<int> f[4];
        for (int i = 0; i < n; i++) {
            f[tp[i]].push_back(i);
        }

        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j < f[i].size(); j++) {
                cout << f[i][j] + 1 << ' ' << f[i^3][j] + 1 << '\n';
            }
        }
    }
}