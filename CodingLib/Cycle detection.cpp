    vector<int> adj[N];
    vector<int> parent(N), color(N);
    int cycle_start, cycle_end;

    bool dfs(int v, int par) { // Returns true if there is a cycle in the graph
        color[v] = 1;
        for (int u : adj[v]) {
            // if(u == par) continue; // Uncomment if the graph is UNDIRECTED
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u, parent[u]))
                    return true;
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    }

    // Find and print the cycle
    void find_cycle() {
        cycle_start = -1;

        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v, parent[v]))
                break;
        }

        if (cycle_start == -1) {
            cout << "Acyclic" << endl;
        } else {
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            reverse(cycle.begin(), cycle.end());

            cout << "Cycle found: ";
            for (int v : cycle)
                cout << v << " ";
            cout << endl;
        }
    }