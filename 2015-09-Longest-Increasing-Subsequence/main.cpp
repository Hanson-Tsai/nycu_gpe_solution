#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;

    while(cin >> n){
        vector<int> input(n);
        vector<int> LIS(n, 1);

        for(int i=0; i<n; i++){
            cin >> input[i];
        }

        int result = 1;
        for(int i=1; i<n; ++i){
            for(int j = 0; j <i; ++j){
                if(input[j] < input[i]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }

            result = max(result, LIS[i]);
        }

        cout << result << endl;
    }
}