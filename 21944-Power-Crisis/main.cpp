#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;

    while(cin >> n && n){
        for(int m=1; m<n; ++m){
            int f = 0;
            for(int i=1; i<n; ++i){
                f = (f + m) % i;
            }

            if(f == 11){
                cout << m << endl;
                break;
            }
        }
    }
}