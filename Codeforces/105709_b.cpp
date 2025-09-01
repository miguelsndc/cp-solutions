#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        string &lca = a[i]; bool is = true;
        for (int j = 0; j < n and is; j++) {
            int sz = a[j].size() - lca.size();
            if (sz < 0) {
                is = false; 
                break;
            }

            for (int k = sz; k < a[j].size(); k++) {
                if (lca[k - sz] != a[j][k]) {
                    is = false;
                    break;
                }
            }
        }

        if (is) {
            cout << a[i];
            return 0;
        }
    }

    cout << "Not found";
}