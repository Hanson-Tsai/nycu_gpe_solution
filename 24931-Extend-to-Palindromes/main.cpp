#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string strA, strB;

vector<int> build_failure(){
    int m = strB.size();
    vector<int> b(m, -1);
    int k = 0;

    for(int j=1; j<m; ++j){
        k = b[j-1];
        while(k>=0 && strB[k+1] != strB[j])
            k = b[k];

        if(strB[k+1] == strB[j])
            b[j] = k+1;
    }

    return b;
}

int KMP(){
    vector<int> next = build_failure();

    int n = strA.size(), m = strB.size();
    int i=0, j=0;

    while(i<n && j<m){
        if(strA[i] == strB[j]){
            i++;
            j++;
        }else if(j > 0){
            j = next[j-1] + 1;
        }else{
            i++;
        }
    }

    return j;
}

int main(){

    while(cin >> strA){
        strB = strA;
        reverse(strB.begin(), strB.end());

        int n = KMP();

        cout << strA << strB.substr(n) << endl;
    }

    return 0;
}
