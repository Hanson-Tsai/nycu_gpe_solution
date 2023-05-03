#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct adj_node {
    int next_node;
    int edge_weight;
};

const int max_node = 10005;
vector<adj_node> adj_list[max_node];
int ans;



int dfs(int cur_node, int prev_node){
    int max_route = 0;

    for(auto &adjNode : adj_list[cur_node]){
        if(adjNode.next_node == prev_node)continue;

        int route = dfs(adjNode.next_node, cur_node) + adjNode.edge_weight;

        ans = max(ans, max_route + route);
        max_route = max(max_route, route);
    }

    return max_route;
}

int main(){
    string buffer;

    int head, tail, weight;
    while(!cin.eof()){
        for(int i=0; i<max_node; i++){
            adj_list[i].clear();
        }
        ans = 0;

        getline(cin, buffer);
        adj_node tmp;
        while(buffer.length()>0 && !cin.eof()){
            stringstream ss(buffer);
            ss >> head >> tail >> weight;

            tmp.edge_weight = weight;

            tmp.next_node = tail;
            adj_list[head].push_back(tmp);

            tmp.next_node = head;
            adj_list[tail].push_back(tmp);

            getline(cin, buffer);
        }

        dfs(1, 0);
        cout << ans << endl;
    }

    return 0;
}