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
#define vc vector<char>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int n, m;
bool is_corner(int i, int j, vs &labyrinth) {
    return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
}

vc directions_char = {'U', 'D', 'L', 'R'};
vector<vi> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void monsters_bfs(vs &graph, queue<pii> q, vector<vi> &dist) {
    int row, col;
    while (!q.empty()) {
        row = q.front().f, col = q.front().s;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int r = row + directions[k][0];
            int c = col + directions[k][1];
            if (r < 0 || c < 0 || r >= n || c >= m || graph[r][c] == '#' || graph[r][c] == 'M') {
                continue;
            }
            pii p = make_pair(r, c);
            graph[r][c] = '#';
            dist[r][c] = dist[row][col] + 1;
            q.push(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vs graph(n);
    vs m_cp(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        graph[i] = m_cp[i] = s;
    }

    vector<vi> m_dist(n, vi(m, -1));
    queue<pii> monsters_q;
    pii a_coord;
    vector<vi> prev(n, vi(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A') {
                prev[i][j] = -2;
                a_coord = make_pair(i, j);
            } else if (graph[i][j] == 'M') {
                m_dist[i][j] = 0;
                monsters_q.push(make_pair(i, j));
            }
        }
    }
    monsters_bfs(m_cp, monsters_q, m_dist);

    int row, col;
    queue<pii> q;
    int i = a_coord.f;
    int j = a_coord.s;
    q.push(make_pair(i, j));
    graph[i][j] = '#';
    vector<vi> player_dist(n, vi(m, -1));
    player_dist[i][j] = 0;
    while (!q.empty()) {
        row = q.front().f, col = q.front().s;
        q.pop();
        if (is_corner(row, col, graph) && (player_dist[row][col] < m_dist[row][col] || m_dist[row][col] == -1)) {
            cout << "YES" << '\n';
            string path;
            while (prev[row][col] != -2) {
                int dir = prev[row][col];
                path += directions_char[dir];
                row -= directions[dir][0];
                col -= directions[dir][1];
            }
            cout << path.size() << '\n';
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
            }
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int r = row + directions[k][0];
            int c = col + directions[k][1];
            if (r < 0 || c < 0 || r >= n || c >= m || graph[r][c] == '#' || graph[r][c] == 'M') {
                continue;
            }
            graph[r][c] = '#';
            prev[r][c] = k;
            player_dist[r][c] = player_dist[row][col] + 1;
            q.push(make_pair(r, c));
        }
    }
    cout << "NO";
    return 0;
}