#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

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
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int src = n + m + 2;
    int sink = n + m + 1;
    Dinic<int> flow(n + m + 3);
    vii edges;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        flow.addEdge(a, n + b, 1);
        edges.push_back({a, n + b});
    }

    for (int i = 1; i <= n; i++) {
        flow.addEdge(src, i, 1);
    }

    for (int i = 1; i <= m; i++) {
        flow.addEdge(n + i, sink, 1);
    }

    int size = flow.maxFlow(src, sink);
    cout << size << '\n';

    int c = 0;
    for (auto e: edges) {
        bool match = false;
        for (int idx : flow.edges[e.first]) {
            if (flow.list[idx].to == e.second && (idx % 2 == 0) && flow.list[idx].cap == 0) {
                match = true;
                break;
            }
        }
        if (match && c < size) {
            cout << e.first << " " << e.second - n << '\n';
            c++;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}
