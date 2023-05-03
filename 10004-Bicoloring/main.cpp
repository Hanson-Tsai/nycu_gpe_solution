#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static const int BLACK = 0;
static const int WHITE = 1;
static const int UNKNOWN = 2;

int main(){

    int node_num;
    int edge_num;

    while(cin >> node_num, node_num != 0) {

        vector<vector<int>> Graph(node_num);
        vector<int> nodeColer(node_num, UNKNOWN);
        bool result = true;

        cin >> edge_num;

        for(int i=0; i<edge_num; i++){
            int head;
            int tail;
            cin >> head >> tail;
            Graph[head].push_back(tail);
            Graph[tail].push_back(head);
        }

        queue<int> q;
        nodeColer[0] = BLACK;
        q.push(0);
        while(!q.empty() && result){
            int node1 = q.front();
            q.pop();

            for(int i=0; i<Graph[node1].size(); i++){
                int node2 = Graph[node1][i]; // find a adjacent node from node1's adjcent list

                if(nodeColer[node2] == nodeColer[node1]){
                    result = false;
                    break;
                }else if(nodeColer[node2] == UNKNOWN){
                    nodeColer[node2] = !nodeColer[node1];
                    q.push(node2);
                }
            }
        }

        if(result){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}