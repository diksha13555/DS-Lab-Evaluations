#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int start, vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    cout << node << " ";
    for (int x : adj[node]) if (!vis[x]) dfsUtil(x, adj, vis);
}

void dfs(int start, vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    dfsUtil(start, adj, vis);
    cout << endl;
}

struct Edge {
    int u, v, w;
};

int findp(int x, vector<int>& p) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x], p);
}

void unite(int a, int b, vector<int>& p, vector<int>& r) {
    a = findp(a, p);
    b = findp(b, p);
    if (a != b) {
        if (r[a] < r[b]) p[a] = b;
        else if (r[b] < r[a]) p[b] = a;
        else {
            p[b] = a;
            r[a]++;
        }
    }
}

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    vector<int> p(n), r(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    int total = 0;
    for (auto e : edges) {
        if (findp(e.u, p) != findp(e.v, p)) {
            unite(e.u, e.v, p, r);
            total += e.w;
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    cout << total << endl;
}

void prim(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int w = p.first, node = p.second;
        if (vis[node]) continue;
        vis[node] = 1;
        total += w;
        cout << node << " " << w << endl;
        for (auto x : adj[node]) if (!vis[x.first]) pq.push({x.second, x.first});
    }
    cout << total << endl;
}

void dijkstra(int start, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first, node = p.second;
        if (d > dist[node]) continue;
        for (auto x : adj[node]) {
            if (dist[node] + x.second < dist[x.first]) {
                dist[x.first] = dist[node] + x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    for (int i = 0; i < n; i++) cout << i << " " << dist[i] << endl;
}

int main() {
    vector<vector<int>> adj1 = {
        {1,2},
        {0,3},
        {0,3},
        {1,2}
    };

    bfs(0, adj1);
    dfs(0, adj1);

    vector<Edge> edges = {
        {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}
    };
    kruskal(4, edges);

    vector<vector<pair<int,int>>> adj2 = {
        {{1,2},{2,4}},
        {{0,2},{2,1},{3,7}},
        {{0,4},{1,1},{3,3}},
        {{1,7},{2,3}}
    };

    prim(4, adj2);
    dijkstra(0, adj2);

    return 0;
}