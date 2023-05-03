#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <cstring>

using namespace std;

vector<int> prime_table;
bool table[47000];

int make_table(){
    memset(table, true, sizeof(table));
    int prime_count = 0;

    table[0] = false;
    table[1] = false;

    for(int i=2; i<47000; ++i){
        if (table[i]){
            prime_table.push_back(i);
            prime_count++;
            for(long long j=(long long)i*i; j<47000; j=j+i){
                table[j] = false;
            }
        }
    }

    return prime_count;
}

bool is_prime(int value) {
    if(value < 47000) {
        return table[value];
    }
    for(int i = 0; i < prime_table.size() && prime_table[i] < value; ++i) {
        if(value % prime_table[i] == 0) return false;
    }
    return true;
}

void parse(int L, int U, int prime_count){
    vector<int> ans;

    for(long long i=L; i<=U; ++i){
        if (is_prime(i)){
            ans.push_back(i);
        }
    }
    int ans_count = ans.size();

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

    int prime_count = make_table();
    int L, U;
    while(cin >> L >> U){
        parse(L, U, prime_count);
    }
}
