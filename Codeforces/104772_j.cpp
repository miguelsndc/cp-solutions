#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // achar o minimo
    int cnt = 0;
    for (int i = 0, j = 0; i < n and j < n; i++) {
        while (j < n and a[i] > b[j]) j++;
        if (j<n and a[i] < b[j]) {
//            cout << "fazendo pra " << a[i] << ' ' << b[j] << '\n';
            cnt++, j++;
        }
    }
    int mini = n - cnt;
    cnt = 0;
    for (int i = 0, j = 0; i < n and j < n; i++) {
        while(j < n and a[j] < b[i]) j++;
        if (j<n and a[j] > b[i]) cnt++, j++;
    }
    int maxx = cnt;

    cout << maxx - mini + 1 << '\n';
    for (int i = mini; i <= maxx; i++) cout << i << ' ';
}
