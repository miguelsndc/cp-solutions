#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    int m[h][w];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << m[j][i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}