#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int find(vector<int> &set)
{
    for (int d = set.size() - 1; d >= 0; d--)
    {
        for (int a = 0; a < set.size(); a++)
        {
            for (int b = a + 1; b < set.size(); b++)
            {
                for (int c = b + 1; c < set.size(); c++)
                {
                    if (set[a] + set[b] + set[c] == set[d] && a != d && b != d && c != d)
                        return set[d];
                }
            }
        }
    }

    return INT_MAX;
}

int main()
{
    int n;

    while (cin >> n, n)
    {
        vector<int> set(n);

        for (int i = 0; i < n; i++)
        {
            cin >> set[i];
        }

        sort(set.begin(), set.end());

        int d = find(set);

        if (d != INT_MAX)
            cout << d << endl;
        else
            cout << "no solution" << endl;
    }

    return 0;
}