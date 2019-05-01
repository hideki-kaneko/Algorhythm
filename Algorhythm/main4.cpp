#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=jp

#define N_MAX 100
#define C_MAX 101

int g_Cost[N_MAX + 1][N_MAX + 1];   // g_Cost[i][j]: (Mi*Mi+1*...Mj)の計算回数
int g_C[C_MAX];                     // 各行列の列数(g_C[0]:最初の行列の行数 g_C[n]:行列nの列数)

// (Mi*Mi+1*...Mj)の計算回数を求めます
int CalcCost(int i, int j)
{
    assert(i > 0);
    if (g_Cost[i][j] != -1)     // コストが計算済みの時
    {
        return g_Cost[i][j];
    }
    else if (i == j)
    {
        g_Cost[i][j] = 0;
        return 0;               // 行列1つは計算回数0
    }
    int minCost = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int c1 = CalcCost(i, k);
        int c2 = CalcCost(k + 1, j);
        int cost = CalcCost(i, k) + CalcCost(k + 1, j) + g_C[i - 1] * g_C[k] * g_C[j];
        if (cost <= minCost)
        {
            minCost = cost;
            g_Cost[i][j] = cost;
        }
    }

    return minCost;
}

int main4()
{
    int n;            // 行列の数
    int _c;           // 入力用ダミー変数
    
    for (int i = 0; i < N_MAX + 1; i++)
    {
        for (int j = 0; j < N_MAX + 1; j++)
        {
            g_Cost[i][j] = -1;
        }
    }

    // 入力
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cin >> g_C[0] >> g_C[1];
        }
        else
        {
            cin >> _c >> g_C[i + 1];
        }
    }

    //計算
    int ans = CalcCost(1, n);
    cout << ans << endl;

    return 0;
}