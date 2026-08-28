#include <bits/stdc++.h>
using namespace std;

void bfs (int src, vector<vector<int>>& adj_list, vector<bool>& vis, vector<int>& level, vector<int>& parent)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par]+1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src, distination;
    cin >> src >> distination;

    vector<bool> vis(n+9, false);
    vector<int> level(n+9, -1), parent(n+9, -1);
    bfs(src, adj_list, vis, level, parent);

    vector<int> path;
    int vertex = distination;

    while (vertex != -1)
    {
        path.push_back(vertex);
        vertex = parent[vertex];
    }

    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
    
    return 0;
}