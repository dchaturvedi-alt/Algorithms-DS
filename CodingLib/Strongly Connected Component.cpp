int grp = 0;
vector<int> adj[N], radj[N], exit_order, cond[N];
vi vis(N), comp(N);

void dfs(int u)
{
	vis[u] = 1;
	for(auto &it:adj[u])
	{
		if(!vis[it])
			dfs(it);
	}
	exit_order.push_back(u);
}

void dfs2(int u, int val)
{
	comp[u] = val;
	cond[val].pb(u);
	for(auto &it:radj[u])
	{
		if(comp[it] == -1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{
	adj[from].push_back(to);
	radj[to].push_back(from);
}

void scc()
{
	for(int i = 1; i <= n; i++)
		comp[i] = -1;

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(exit_order.begin(), exit_order.end());

	for(auto &it : exit_order)
	{
		if(comp[it] == -1)
			dfs2(it, ++grp);
	}

}