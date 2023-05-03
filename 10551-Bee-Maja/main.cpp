#include <iostream>
#include <set>

using namespace std;

#define MAXN 100200

int offset[5][2] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
pair<int, int> maja[MAXN + 2000];

int main()
{
    for (int i = 1, j = 1, k = 0; i < MAXN; i += j, j += 6, k++)
    {
        // cout << "[-----Loop num-----] = " << k << endl;

        // cout << "-----first part-----" << endl;
        maja[i] = make_pair(0, k);
        // cout << i << " -> (" << 0 << "," << k << ")" << endl;

        // cout << "-----second part-----" << endl;
        for (int m = 0; m < k; m++)
        {
            maja[i - m] = make_pair(m, k - m);
            // cout << i - m << " -> (" << m << "," << k - m << ")" << endl;
        }

        // cout << "-----third part-----" << endl;
        int current = i;
        for (int m = 0; m < 5; m++)
        {
            for (int n = 0; n < k; n++)
            {
                int x = maja[current].first + offset[m][0];
                int y = maja[current].second + offset[m][1];
                maja[current + 1] = make_pair(x, y);
                // cout << current + 1 << " -> (" << x << "," << y << ")" << endl;

                current++;
            }
        }
    }

    int willi;
    while(cin >> willi){
        cout << maja[willi].first << ' ' << maja[willi].second << endl;
    }
}