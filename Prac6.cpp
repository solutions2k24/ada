// DFS BFS
#include <bits/stdc++.h>
using namespace std;
void DFS(int vertex, vector<vector<int>> graph, vector<int> &vis, vector<int> &v1)
{
    vis[vertex] = 1;
    v1.push_back(vertex);

    for(auto &value : graph[vertex])
    {
        if(vis[value]!=1)
        {
            vis[value] = 1;
            DFS(value, graph, vis,  v1);
        }
    }
}
void BFS(int vertex, vector<vector<int>> graph, vector<int> &vis, vector<int> &v2)
{
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;

    while(!q.empty())
    {
        int vertex = q.front();
        v2.push_back(vertex);
        q.pop();
        for(auto &value : graph[vertex])
        {
            if(vis[value]!=1)
            {
                vis[value] = 1;
                q.push(value);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> v1;
    vector<int> vis1(n+1, -1);
    DFS(1, graph, vis1, v1);

    cout << "DFS : ";
    for(auto &value : v1)
    {
        cout << value << " ";
    }
    cout << endl;

    
    vector<int> v2;
    vector<int> vis2(n+1, -1);
    BFS(1, graph, vis2, v2);
    
    cout << "BFS : ";
    for(auto &value : v2)
    {
        cout << value << " ";
    }
    cout << endl;


    int count = 0;
    vector<int> v3;
    vector<int> vis3(n+1, -1);
    for(int i=1; i<=n; i++)
    {
        if(vis3[i]==-1)
        {
            count++;
            DFS(i, graph, vis3, v3);
        }
    }

    if(count==1)
    {
        cout << "Graph is connected" << endl;
    }
    else
    {
        cout << "The graph has " << count << " connected components" << endl;
    }


}