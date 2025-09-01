#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

struct Edge {
    Edge(int a, T b){to = a;cap = b;}
    int to;
    T cap;
};
template <class T = i64>
class Dinic {
    public:
    int n;
    std::vector<std::vector<int> > edges;
    std::vector<Edge> list;
    std::vector<int> h, pt;
    
    T dfs(int on, int sink, T flow = 1e9) {
        if(flow == 0) {
            return 0;
        } if(on == sink) {
            return flow;
        }
        for(; pt[on] < (int) edges[on].size(); pt[on]++) {
            int cur = edges[on][pt[on]];
            if(h[on] + 1 != h[list[cur].to]) {
                continue;
            }
            T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
            if(got) {
                list[cur].cap -= got;
                list[cur ^ 1].cap += got;
                return got;
            }
        }
        return 0;
    }
    
    bool bfs(int src, int sink) {
        h = std::vector<int>(n, n);
        h[src] = 0;
        std::queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int on = q.front();
            q.pop();
            for(auto a : edges[on]) {
                if(list[a].cap == 0) {
                    continue;
                }
                int to = list[a].to;
                if(h[to] > h[on] + 1) {
                    h[to] = h[on] + 1;
                    q.push(to);
                }
            }
        }
        return h[sink] < n;
    }

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> has(505, vector<int>(505));
    Dinic din(505);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        has[a][b] = has[b][a] = true;
        din.addEdge(a, b, c);
    }
    din.maxFlow(1, n);
      // Do a BFS to find reachable vertices
    vector<bool> visited(505, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int edgeId : din.edges[v]) {
            Edge& e = din.list[edgeId];
            
            // If there's remaining capacity and destination not visited
            if (e.cap > 0 && !visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }

    // Find min-cut edges
    vector<pair<int,int>> minCutEdges;
    for (int i = 0; i < (int)din.list.size(); i += 2) {
        Edge& e = din.list[i];
        // Check original forward edges
        if (visited[e.from] && !visited[e.to]) {
            // Original edge indices are always even
            minCutEdges.push_back({e.from, e.to});
        }
    }
}