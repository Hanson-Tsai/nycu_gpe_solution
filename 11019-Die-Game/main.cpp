#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(cin >> n, n !=0){
        vector<int> dice = {1,2,3,4,5,6}; // TOP = index zero
        vector<int> prev_dice = dice;
        string s;

        for(int i=0; i<n; ++i){
            cin >> s;

            if(s == "north"){
                dice[0] = prev_dice[4];
                dice[1] = prev_dice[0];
                dice[4] = prev_dice[5];
                dice[5] = prev_dice[1];
            }else if(s == "south"){
                dice[0] = prev_dice[1];
                dice[1] = prev_dice[5];
                dice[4] = prev_dice[0];
                dice[5] = prev_dice[4];
            }else if(s == "west"){
                dice[0] = prev_dice[3];
                dice[2] = prev_dice[0];
                dice[5] = prev_dice[2];
                dice[3] = prev_dice[5];
            }else if(s == "east"){
                dice[0] = prev_dice[2];
                dice[2] = prev_dice[5];
                dice[5] = prev_dice[3];
                dice[3] = prev_dice[0];
            }

            prev_dice = dice;
        }

        cout << dice[0] << endl;
    }
}