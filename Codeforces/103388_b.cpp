#include <bits/stdc++.h>
#define array vector
#define scan cin
#define print cout
using namespace std;
using str = string;

struct suffix_array {
    int n;
    str s;
    array<int> suf, lcp;
    array<int> rank, temp;

    suffix_array(str &base): n(base.length() + 1), s(base + '$'), suf(n), lcp(n), rank(n), temp(n) {
        for (int i = 0; i < n; ++i) {
            suf[i] = i;
            rank[i] = s[i];
        }
        for (int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            temp[suf[0]] = 0; 
            for (int i = 1; i < n; ++i) {
                int prev = suf[i - 1];
                int curr = suf[i];
                int prevSecond = (prev + k < n) ? rank[prev + k] : 0;
                int currSecond = (curr + k < n) ? rank[curr + k] : 0;
                if (rank[prev] == rank[curr] && prevSecond == currSecond) {
                    temp[curr] = temp[prev];
                } else {
                    temp[curr] = temp[prev] + 1;
                }
            }
            swap(rank, temp);
            if (rank[suf[n - 1]] == n - 1) break;
        }
    }

    void counting_sort(int k) {
        int m = max(255, n) + 1;
        array<int> f(m);
        for (int i = 0; i < n; ++i) {
            int r = (suf[i] + k < n) ? rank[suf[i] + k] : 0;
            f[r] += 1;
        }
        for (int i = 1; i < m; ++i) {
            f[i] += f[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            int r = (suf[i] + k < n) ? rank[suf[i] + k] : 0;
            f[r] -= 1;
            temp[f[r]] = suf[i];
        }
        swap(suf, temp);
    }

    void longest_common_prefix() {
        array<int> inv(n);
        for (int i = 0; i < n; ++i) {
            inv[suf[i]] = i;
        }
        int l = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (inv[i] == 0) {
                lcp[inv[i]] = 0;
                continue;
            }
            int j = suf[inv[i] - 1];
            while (i + l < n && j + l < n && s[i + l] == s[j + l]) l++;
            lcp[inv[i]] = l;
            l = max(l - 1, 0);
        }
    }
};

int solve() {
    int n, m; scan >> n >> m;
    str s; scan >> s;
    str a;
    while (m--) {
        str x; scan >> x;
        a += x;
        a += 'D';
    }
    a.pop_back();
    int k = a.size();
    a += 'A';
    str f1 = a + s;
    suffix_array f(f1);
    f.longest_common_prefix();
    pair<int, int> best = {-1, 0};
    for (int i = 1; i < (int)f.lcp.size(); ++i) {
        if (f.suf[i] >= k && f.suf[i - 1] <= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i]};
            }
        } else if (f.suf[i] <= k && f.suf[i - 1] >= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i - 1]};
            }
        }
    }
    int worst = best.first;
    int div = (best.second - k) + best.first / 2;
    str xyz = s.substr(div - 1) + s.substr(0, div - 1);
    str f2 = a + xyz;
    f = suffix_array(f2);
    f.longest_common_prefix();
    best = {-1, 0};
    for (int i = 1; i < (int)f.lcp.size(); ++i) {
        if (f.suf[i] >= k && f.suf[i - 1] <= k) {
            if (f.lcp[i] > best.first) {
                best = {f.lcp[i], f.suf[i]};
            }
        } else if (f.suf[i] <= k && f.suf[i - 1] >= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i - 1]};
            }
        }
    }
    worst = min(worst, best.first);
    str z = s.substr(div) + s.substr(0, div);
    str f3 = a + z;
    f = suffix_array(f3);
    f.longest_common_prefix();
    best = {-1, 0};
    for (int i = 1; i < (int)f.lcp.size(); ++i) {
        if (f.suf[i] >= k && f.suf[i - 1] <= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i]};
            }
        } else if (f.suf[i] <= k && f.suf[i - 1] >= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i - 1]};
            }
        }
    }
    worst = min(worst, best.first);
    if (div + 1 >= (int)s.size()) return worst;
    str zzz = s.substr(div + 1) + s.substr(0, div + 1);
    str f4 = a + zzz;
    f = suffix_array(f4);
    f.longest_common_prefix();
    best = {-1, 0};
    for (int i = 1; i < (int)f.lcp.size(); ++i) {
        if (f.suf[i] >= k && f.suf[i - 1] <= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i]};
            }
        } else if (f.suf[i] <= k && f.suf[i - 1] >= k) {
            if (f.lcp[i] >= best.first) {
                best = {f.lcp[i], f.suf[i - 1]};
            }
        }
    }
    return min(worst, best.first);
}

signed main() {
    ios::sync_with_stdio(false);
    scan.tie(nullptr);
    print << solve() << '\n';
    return 0;
}
