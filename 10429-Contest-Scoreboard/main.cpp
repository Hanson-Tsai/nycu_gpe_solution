#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Team {
    bool join;
    int contestant_num;
    int solved_problem;
    int penalty;
    int error[10];
};

bool cmp(Team a, Team b){
    if(a.solved_problem > b.solved_problem)return true;
    if(a.solved_problem < b.solved_problem)return false;
    if(a.penalty < b.penalty)return true;
    if(a.penalty > b.penalty)return false;
    if(a.contestant_num < b.contestant_num)return true;

    return false;
}

int main(){
    int n;
    cin >> n;

    getchar();
    getchar();
    string s;

    vector<Team> Teams(105);
    int contestant_num, problem_num, time;
    char type;
    while(n--){
        for(int i=0; i<105; ++i){
            Teams[i].join = false;
            Teams[i].contestant_num = i;
            Teams[i].solved_problem = 0;
            Teams[i].penalty = 0;
            memset(Teams[i].error, 0, sizeof(Teams[i].error));
        }

        while (getline(cin, s) && s!="")
        {
            stringstream ss(s);
            ss >> contestant_num >> problem_num >> time >> type;

            Teams[contestant_num].join = true;
            if(Teams[contestant_num].error[problem_num] == -1)continue;

            if(type == 'C'){
                Teams[contestant_num].penalty += Teams[contestant_num].error[problem_num]*20 + time;
                Teams[contestant_num].solved_problem++;
                Teams[contestant_num].error[problem_num] = -1;
            }else if(type == 'I'){
                Teams[contestant_num].error[problem_num]++;
            }
        }
        sort(Teams.begin(), Teams.end(), cmp);

        for(int i=0; i<105; ++i){
            if(Teams[i].join){
                printf("%d %d %d\n", Teams[i].contestant_num, Teams[i].solved_problem, Teams[i].penalty);
            }
        }

        if(n>0)printf("\n");
    }

    return 0;
}