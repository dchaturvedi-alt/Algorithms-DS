//Distance stores levels, and ways stores the number of ways to get from kth vertex to any other vertex with the shortest path taken
	vi vis(N), dist(N), ways(N), par(N);

	void bfs(int v)
	{	
		fill(all(vis), 0);
		fill(all(dist), 0);
		fill(all(ways), 0);
		queue<int> q;
		q.push(v);
		ways[v]=1;
		vis[v]=1;
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			for(auto it : adj[node])
			{
				if(!vis[it])
				{
					dist[it] = dist[node]+1;
					vis[it] = 1;
					ways[it] += ways[node];
					par[it] = node;
					q.push(it);
				}
				else
				{
					if(dist[node]+1 == dist[it])
					{
						ways[it] += ways[node];
					}
				}
			}
		}
	}