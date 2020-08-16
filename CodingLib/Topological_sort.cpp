vector<int> order; //Stores the Topological Order
 
bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	order.clear();
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:adj[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	int idx = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		idx++;
		pos[u] = idx;
		for(auto &v:adj[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}