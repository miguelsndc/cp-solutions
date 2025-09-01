#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct Clock {
    string s;
    chrono::_V2::system_clock::time_point start, end;

    void snapshot(string fn) {
        s = fn;
        start = chrono::high_resolution_clock::now();
    }

    void time_taken() {
        end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        std::cout << "Time taken for " << s << " was: " << duration.count() << " ms\n\n";
    }
};

Clock c;
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};
gp_hash_table<int, int, chash> d1;
void solve() {
    d1.clear();
    int n;
    cin >> n;
    vc<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (v.size() < 27) {
            v.push_back(x);
        }
    }

    int m = v.size();
    auto f1 = [&](auto&& self, int i, int n, int a, int b) {
        if (i == n) {
            if (a != b and (a > 0 or b > 0)) {
                d1[a - b] = true;
            }
            return;
        }
        self(self, i + 1, n, a + v[i], b);
        self(self, i + 1, n, a, b + v[i]);
        self(self, i + 1, n, a, b);
    };

    int found = -1;
    vc<int> ans_v1, ans_v2, ans_v3, ans_v4, av, bv;
    auto f2 = [&](auto&& self, int i, int n, int a, int b) {
        if (found != -1) return;
        if (i == n) {
            if (a != b and (av.size() > 0 or bv.size() > 0) and found == -1) {
                if (d1.find(b - a) != d1.end()) {
                    ans_v1 = av;
                    ans_v2 = bv;
                    found = b - a;
                }
            }
            return;
        }
        if (found == -1) {
            av.push_back(i);
            self(self, i + 1, n, a + v[i], b);
            av.pop_back();
            bv.push_back(i);
            self(self, i + 1, n, a, b + v[i]);
            bv.pop_back();
            self(self, i + 1, n, a, b);
        }
    };

    int mid = (m) / 2;

    // c.snapshot("f1");
    f1(f1, 0, mid, 0, 0);
    // c.time_taken();
    // c.snapshot("f2");
    f2(f2, mid, m, 0, 0);
    // c.time_taken();

    if (found == -1) {
        cout << -1 << '\n';
        return;
    }

    bool got = false;
    auto f3 = [&](auto&& self, int i, int n, int a, int b) {
        if (got) return;
        if (i == n) {
            int dif = a - b;
            if (!got and (found == dif) and (av.size() > 0 or bv.size() > 0)) {
                ans_v3 = av;
                ans_v4 = bv;
                got = true;
            }
            return;
        }
        if (!got) {
            av.push_back(i);
            self(self, i + 1, n, a + v[i], b);
            av.pop_back();
            bv.push_back(i);
            self(self, i + 1, n, a, b + v[i]);
            bv.pop_back();
            self(self, i + 1, n, a, b);
        }
    };

    // c.snapshot("f3");
    f3(f3, 0, mid, 0, 0);
    // c.time_taken();

    vc<int> aa, bb;
    for (int x : ans_v1) aa.push_back(x + 1);
    for (int x : ans_v3) aa.push_back(x + 1);

    for (int x : ans_v2) bb.push_back(x + 1);
    for (int x : ans_v4) bb.push_back(x + 1);

    cout << aa.size() << ' ';
    for (int x : aa) cout << x << ' ';
    cout << '\n';

    cout << bb.size() << ' ';
    for (int x : bb) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}