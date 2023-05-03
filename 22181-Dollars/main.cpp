#include <cstdio>

using namespace std;

const int MAX = 30001;
const int coin[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

long long count[MAX];

int main(){
    count[0] = 1;
    for(int i=0; i<11; i++){
        for(int j=coin[i]; j<MAX; j=j+5){
            count[j] += count[j - coin[i]];
        }
    }

    int aa, bb;
    double input;
    while(scanf("%d.%d", &aa, &bb) != EOF){
        input = aa + bb/100.0;
        if(aa==0 && bb==0)break;

        printf("%6.2f%17lld\n", input, count[aa*100+bb]);
    }

    return 0;
}