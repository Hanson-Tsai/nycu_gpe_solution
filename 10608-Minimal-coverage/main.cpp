#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> input, ans;
    while (n)
    {
        n--;

        int M;
        cin >> M;

        input.clear();
        int Li, Ri;
        while ((cin >> Li >> Ri) && (Li != 0 || Ri != 0))
        {
            input.push_back(make_pair(Li, Ri));
        }
        sort(input.begin(), input.end(), cmp);

        ans.clear();
        int left, right;
        left = 0;
        right = 0;
        for (int i = 0; i < input.size(); i++)
        {
            int tmp = -1;
            for (; i < input.size() && input[i].first <= left; i++)
            {
                if (input[i].second > right)
                {
                    right = input[i].second;
                    tmp = i;
                }
            }

            if (tmp == -1)
            {
                break;
            }

            ans.push_back(input[tmp]);
            if (right >= M)
            {
                break;
            }
            left = right;
            i--;
        }

        if (right < M)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }

        if (n > 0)
        {
            printf("\n");
        }
    }
}
