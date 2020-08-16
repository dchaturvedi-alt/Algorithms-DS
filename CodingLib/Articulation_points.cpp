vector<int> tin(N), low(N);
vector<bool> art(N);
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                art[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        art[v] = true;
}
