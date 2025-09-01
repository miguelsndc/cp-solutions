#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int n, m, k;

bool ok(int dc, vi& obj) {
    // can he pack all objects if he discards k from the left ?
    int l = dc;
    int packed = 0;
    int boxi = 0;
    vi boxes(m);

    while(l < obj.size() && boxi < boxes.size()) {
        while(l < obj.size() && (boxes[boxi] + obj[l]) <= k) {
            boxes[boxi] += obj[l];
            l++; packed++;
        } 
        boxi++;
    }

    return boxi != m || packed >= (obj.size() - dc);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vi obj(n); loop(i, 0, n) cin >> obj[i];

    int l = -1, r = n + 1;
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if (ok(m, obj)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << (n - r);
}