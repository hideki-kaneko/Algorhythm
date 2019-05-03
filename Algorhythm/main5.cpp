#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A&lang=jp

#define N_MAX 100

int main5()
{
    int n, k, u, v;
    int adj[N_MAX][N_MAX];

    // ì¸óÕ
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            adj[u - 1][v - 1] = 1;
        }
    }

    // èoóÕ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                cout << adj[i][j];
            }
            else
            {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}