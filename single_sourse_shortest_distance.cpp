#include <bits/stdc++.h>
using namespace std;


void bfs (int src, vector<vector<int>>& adj_list, vector<bool>& vis, vector<int>& level)
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
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    int src, dst;
    cin >> src >> dst;

    vector<bool> vis(n, false);
    vector<int> level(n+9, -1);

    bfs (src, adj_list, vis, level);

    cout << level[dst] << endl;

    return 0;
}

