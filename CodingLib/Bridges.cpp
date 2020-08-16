	vi tin(N), low(N);
	int timer = 0;
	vector<pii> bridges;
	void dfs(int v, int p){
		vis[v] = 1;
		tin[v] = low[v] = timer++;
		for(int u : adj[v]){
			if(u==p) continue;
			if(vis[u])
				low[v] = min(low[v], tin[u]);
			else{
				dfs(u, v);
				low[v] = min(low[v], low[u]);
				if(low[u] > tin[v])
					bridges.pb({v,u});
			}
		}
	}