#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <cstring>

using namespace std;

vector<int> prime_table;

int make_table(int n){
    int prime_count = 0;
    vector<bool> table(n, true);
    table[0] = false;
    table[1] = false;

    for(int i=2; i<n; ++i){
        if (table[i]){
            prime_table.push_back(i);
            prime_count++;
            for(int j=i*i; j<n; j=j+i){
                table[j] = false;
            }
        }
    }

    return prime_count;
}

bool table[10000001];
int ans[10000001];
void parse(int L, int U, int prime_count){
    memset(table, 0, sizeof(table));
    for(int i=0; i<prime_count; ++i){
        int s = (L-1)/prime_table[i]+1;
        if(s < 2)s=2;

        for(unsigned int j=s*prime_table[i]; j<=U; j+=prime_table[i]){
            table[j-L] = 1;
        }
    }

    int ans_count = 0;
    for(unsigned int i=L; i<=U; ++i){
        if (i>1 && !table[i-L]){
            ans[ans_count++] = i;
        }
    }

    if(ans_count < 2){
        cout << "There are no adjacent primes." << endl;
    }else{
        int minimun=INT_MAX, maximum=INT_MIN, min_left, min_right, max_left, max_right;
        for(int i=1; i<ans_count; ++i){
            if(minimun > ans[i] - ans[i-1]){
                minimun = ans[i] - ans[i-1];
                min_left = ans[i-1];
                min_right = ans[i];
            }
            if(maximum < ans[i] - ans[i-1]){
                maximum = ans[i] - ans[i-1];
                max_left = ans[i-1];
                max_right = ans[i];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", min_left, min_right, max_left, max_right);
    }
}

int main(){

    int prime_count = make_table(sqrt(INT_MAX));
    int L, U;
    while(cin >> L >> U){
        parse(L, U, prime_count);
    }
}
