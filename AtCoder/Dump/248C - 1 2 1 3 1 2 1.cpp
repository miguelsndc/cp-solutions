#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------

void S(int n) {
    if (n == 1) {
        cout << 1 << ' ';
        return;
    }

    S(n - 1);
    cout << n << ' ';
    S(n - 1);
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    S(n);

    return 0;
}