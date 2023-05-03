#include <bits/stdc++.h>

using namespace std;


int main(){
    string a;
    string b;

    int tableA[26];
    int tableB[26];
    char tmp;

    while(getline(cin, a) && getline(cin, b)){
        memset(tableA, 0, sizeof(tableA));
        memset(tableB, 0, sizeof(tableB));

        for(int i=0; i<a.size(); i++){
            tableA[a[i]-'a']++;
        }
        for(int i=0; i<b.size(); i++){
            tableB[b[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            int min_num = 0;
            if(tableA[i] && tableB[i]){
                min_num = min(tableA[i], tableB[i]);
            }


            for(int k=1; k<=min_num; k++){
                tmp = i+97;
                cout << tmp;
            }
        }
        cout << endl;
    }
}