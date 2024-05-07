// Dijkstra Algorithm
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0; i<m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

    vector<int> v1(n, 1e9);
    v1[0] = 0;

    pq.push({0, 0});
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        for(auto &value : graph[vertex])
        {
            int sum = wt + value.second;
            if(sum<=v1[value.first])
            {
                v1[value.first] = sum;
                pq.push({sum, value.first});
            }
        }
    }

    for(auto &value : v1)
    {
        cout << value << " ";
    }
    cout << endl;
}