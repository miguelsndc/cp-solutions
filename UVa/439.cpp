#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

vector<vi> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("439.in", "r", stdin);
    string src, dest;

    while (cin >> src >> dest) {
        vector<vi> board(8, vi(8, -1));      // -1 unvisited, 0  visited, 1 src/dest
        vector<vi> dist(8, vi(8, 1e9 + 1));  // -1 unvisited, 0  visited, 1 src/dest
        int a = src[1] - '0';
        int b = dest[1] - '0';
        pii s1 = {src[0] % 97, a - 1};
        pii d1 = {dest[0] % 97, b - 1};
        queue<pii> q;
        dist[s1.f][s1.s] = 0;
        q.push({s1.f, s1.s});
        while (!q.empty()) {
            int i = q.front().f, j = q.front().s;
            q.pop();
            board[i][j] = 0;
            for (auto dir : directions) {
                int r = i + dir[0];
                int c = j + dir[1];
                if (r < 0 || c < 0 || r >= 8 || c >= 8 || board[r][c] == 0) continue;
                if (dist[r][c] > dist[i][j] + 1) {
                    dist[r][c] = dist[i][j] + 1;
                    q.push({r, c});
                }
            }
        }
        cout << "To get from " << src << " to " << dest << " takes " << dist[d1.f][d1.s] << " knight moves." << '\n';
    }

    return 0;
}