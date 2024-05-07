//Topological Sort
#include <bits/stdc++.h>
using namespace std;
#define pb   push_back
void dfs(int vertex, stack<int> &st, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[vertex]=1;

    for(auto &value : graph[vertex])
    {
        if(vis[value]==-1)
        {
            dfs(value, st, vis, graph);
        }
    }
    st.push(vertex);
}
signed main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
    }

    vector<int> vis(n+1, 0);
    stack<int> st;

    for(int i=0; i<=n; i++)
    {
        if(vis[i]==-1)
        {
            dfs(i, st, vis, graph);
        }
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

}