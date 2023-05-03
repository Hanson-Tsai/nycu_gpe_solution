#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int P;
    int Q;
    int weight;
};

void relax(vector<Edge> &edge_list, vector<int> &result){
    for(int i=0; i<edge_list.size(); ++i){
        if(result[edge_list[i].P] != INT_MAX && result[edge_list[i].P] + edge_list[i].weight < result[edge_list[i].Q]){
            result[edge_list[i].Q] = result[edge_list[i].P] + edge_list[i].weight;
        }
    }

    return;
}

void BellmanFord(vector<Edge> &edge_list, vector<int> &result, int start_node){
    int nodes_num = result.size();

    for(int i=1; i<nodes_num-1; ++i){
        relax(edge_list, result);
    }
}

int main(){
    int nodes_num;
    int start_node;
    int cases = 1;

    while(cin >> nodes_num, nodes_num != 0){
        cin >> start_node;

        vector<Edge> edge_list;
        Edge tmp;
        tmp.weight = -1; // Because we want to find the longest path
        while(cin >> tmp.P >> tmp.Q, tmp.P != 0 && tmp.Q != 0){
            edge_list.push_back(tmp);
        }

        vector<int> result(nodes_num+1, INT_MAX); // result[0] will not be used
        result[start_node] = 0;
        BellmanFord(edge_list, result, start_node);

        int shortest_path=INT_MAX, end_node; // longest_paht = (-1)*shortest_path
        for(int i=1; i<result.size(); ++i){
            if(result[i] < shortest_path){
                shortest_path = result[i];
                end_node = i; // Remember to convert index to corret node in vector
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cases, start_node, (-1)*shortest_path, end_node);
        cases++;
    }
}
