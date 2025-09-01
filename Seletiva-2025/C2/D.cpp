#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w; cin >> h >> w;
    vector<vector<int>> L(h, vector<int>(w));
    vector<vector<int>> R(h, vector<int>(w));
    vector<vector<int>> U(h, vector<int>(w));
    vector<vector<int>> D(h, vector<int>(w));

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    for (int i = 0; i < h; i++) {
        int p = 1;
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') p = 1;
            else L[i][j] = p++;
        }
    }

    for (int i = 0; i < h; i++) {
        int p = 1;
        for (int j = w - 1; j >= 0; j--) {
            if (s[i][j] == '#') p = 1;
            else R[i][j] = p++;
        }
    }

    for (int i = 0; i < w; i++) {
        int p = 1;
        for (int j = 0; j < h; j++) {
            if (s[j][i] == '#') p =1;
            else D[j][i] = p++;
        }
    }

    for (int i = 0; i < w; i++) {
        int p = 1;
        for (int j = h - 1; j >= 0; j--) {
            if (s[j][i] == '#') p =1;
            else U[j][i] = p++;
        }
    }

    int maxn = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            maxn = max(maxn, L[i][j] + R[i][j] + D[i][j] + U[i][j] - 3);
        }
    }

    cout << maxn;
}