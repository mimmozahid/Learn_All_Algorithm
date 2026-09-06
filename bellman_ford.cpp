#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

class Edge
{
    int a, b, c;
    public:
        Edge (int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, e;
    cin >> n >> e;

    // vector<Edge> edge_list;
    vector<tuple<int, int , int>> edge_list;
    vector<int> dis (n, INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); //* if undirected graph
        
        edge_list.push_back ({a, b, c});
        edge_list.push_back ({b, a, c}); //! if undirected graph
    }
    
    dis[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        for (auto [a, b, c] : edge_list)
        {
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;
    
    return 0;
}