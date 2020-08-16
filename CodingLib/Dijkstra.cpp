	vi d(N), p(N), vis(N);
	vector<pair<int, int>> adj[N];

	void dijkstra(int s) {
        for(int i=0; i<N; i++)
            d[i] = INF;
        
        d[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (vis[v])
                continue;
            vis[v] = 1;
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }
	vector<int> restore_path(int s, int t) {
	    vector<int> path;

	    for (int v = t; v != s; v = p[v])
	        path.push_back(v);
	    path.push_back(s);

	    reverse(path.begin(), path.end());
	    return path;
	}