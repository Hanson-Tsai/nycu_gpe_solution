#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;
    cin.ignore();

    string s;
    while(n >0){
        n--;

        getline(cin, s);
        stringstream ss(s);
        int tmp;
        vector<int> input;
        int sum = 0;

        while(ss >> tmp){
            sum += tmp;
            input.push_back(tmp);
        }

        if(sum%2 != 0){
            cout << "NO" << endl;
            continue;
        }

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=0; i<input.size(); ++i){
            for(int j=sum; j>=input[i]; --j){
                if(dp[j-input[i]]){
                    dp[j] = true;
                }
            }
        }

        if(dp[sum/2]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}