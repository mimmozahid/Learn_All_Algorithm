#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const ll mxN = 1e5 + 9;
vector<pair<ll, ll>> adj_list[mxN];
vector<ll> dis(mxN, LLONG_MAX);
vector<ll> parent(mxN, -1);

void dijkstra (ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;

            if (par_dis+child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                parent[child_node] = par_node;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back ({b, c});
        adj_list[b].push_back ({a, c});
    }

    dijkstra (1);

    if (dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> path;
    ll vertex = n;

    while (vertex != -1)
    {
        path.push_back (vertex);
        vertex = parent[vertex];
    }
    reverse (path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
    
    return 0;
}