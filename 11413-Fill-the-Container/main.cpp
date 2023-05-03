#include <iostream>
#include <vector>

using namespace std;


int main(){
    int milk_num, container_num;

    while(cin >> milk_num >> container_num){
        vector<int> milks(milk_num, 0);

        int total_milks = 0;
        int max_milks = 0;
        for(int i=0; i<milk_num; i++){
            cin >> milks[i];

            total_milks += milks[i];
            max_milks = max(max_milks, milks[i]);
        }

        int left = max_milks;
        int right = total_milks;
        while(left < right){
            int sum = 0;
            int count = 0;
            int mid = left + (right - left)/2;
            for(int i=0; i<milk_num; i++){
                sum = sum + milks[i];

                if (sum > mid) {
                    count++;
                    sum = milks[i];
                }else if(sum == mid){
                    count++;
                    sum = 0;
                }
            }

            if(sum > 0)count++;

            if(count > container_num)left = mid + 1;
            else right = mid;
        }

        cout << left << endl;
    }

    return 0;
}