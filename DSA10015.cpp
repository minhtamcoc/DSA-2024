#include<bits/stdc++.h>
using namespace std;

int V, E; // số đỉnh và số cạnh của đồ thị
vector<int> v[1001];
bool visited[1001];
vector<pair<int,int>> T;
int parents[1001];

struct rus {
    int u, t, w;
    // w là chi phí của cạnh [u, t];
};

bool cmp(rus a, rus b) {
    return a.w < b.w;
}

void solve() {
    cin >> V >> E;
    for(int i = 1; i <= V; i++) {
        parents[i] = i;
    }
    memset(v, 0, sizeof(v));
    rus adj[E + 1];
    for(int i = 1; i <= E; i++) {
        cin >> adj[i].u >> adj[i].t >> adj[i].w;
    }
    sort(adj + 1, adj + E + 1, cmp);
    int res = 0; // ghi nhận kết quả
    int idx = 1;
    while(T.size() < V - 1) {
        if(parents[adj[idx].u] != parents[adj[idx].t]) {
            res += adj[idx].w;
            T.push_back({adj[idx].u, adj[idx].t});
            int oldParent = parents[adj[idx].t];
            for(int i = 1; i <= V; i++) {
                if(parents[i] == oldParent) {
                    parents[i] = parents[adj[idx].u];
                }
            }
        }
        cout<<res<<endl;
        idx++;
    }
    T.clear();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}