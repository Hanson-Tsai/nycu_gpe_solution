#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        for(int case_num=0; case_num<n; ++case_num){
            if(case_num >=1){
                cout << endl;
            }

            int cpu_num;
            cin >> cpu_num;
            vector<int> cpus(cpu_num+1);
            for(int i=1; i<=cpu_num; i++){
                cpus[i] = i;
            }

            cin.ignore();
            string s;
            char type;
            int node_i, node_j;
            int success_ans=0, fail_ans=0;
            while(getline(cin, s) && s != ""){
                stringstream ss(s);

                ss >> type >> node_i >> node_j;

                if(type == 'c'){
                    int group_i = cpus[node_i], group_j = cpus[node_j];
                    for(int i=1; i <=cpu_num; ++i){
                        if(cpus[i]==group_i || cpus[i]==group_j)
                            cpus[i] = min(group_i, group_j);
                    }
                }else if(type == 'q'){
                    if(cpus[node_i] == cpus[node_j]){
                        success_ans++;
                    }else{
                        fail_ans++;
                    }
                }
            }
            printf("%d,%d\n", success_ans, fail_ans);
        }
    }

    return 0;
}