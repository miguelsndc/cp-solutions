#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N;
    cin >> N;

    if (N == 0) {
        cout << 10 << '\n';
        return;
    }
    if (N == 1) {
        cout << 1 << '\n';
        return;
    }

    map<int,int> primes;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            primes[i]++;
            N /= i;
        }
    }
    if (N > 1) primes[N]++;

    vector<int> ans;

    for (auto &[p, c] : primes) {
        if (p >= 10) {
            cout << -1 << '\n';
            return;
        }
    }

    while (primes[2] >= 3) {
        primes[2] -= 3;
        ans.push_back(8);
    }
    while (primes[3] >= 2) {
        primes[3] -= 2;
        ans.push_back(9);
    }
    while (primes[2] >= 1 && primes[3] >= 1) {
        primes[2]--;
        primes[3]--;
        ans.push_back(6);
    }
    while (primes[2] >= 2) {
        primes[2] -= 2;
        ans.push_back(4);
    }

    while (primes[2]--) ans.push_back(2);
    while (primes[3]--) ans.push_back(3);
    while (primes[5]--) ans.push_back(5);
    while (primes[7]--) ans.push_back(7);

    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
