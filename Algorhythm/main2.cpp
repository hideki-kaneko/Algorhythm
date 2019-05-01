#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp

#define MAX_N 20
#define MAX_Q 200
#define MAX_M 2000

namespace{
int g_N;               // 数列Aの長さ
int g_Dp[MAX_Q][MAX_M];// 計算結果メモ用配列 <-1:未計算 0:false 1:true>
}

// 長さg_Nの数列Aの、i番目以降の要素を足してmが作れる場合Trueを返します
bool Solve(const int* A, int i, int m)
{
    if (m < 0)
    {
        return false;
    }
    else if (g_Dp[i][m] != -1)
    {
        return g_Dp[i][m]; // Solve(i, m)が計算済み
    }
    else if (m == 0)                          // mを作れた
    {
        g_Dp[i][m] = true;
    }
    else if (i >= g_N)                   // N個使ってもmを作れなかった
    {
        g_Dp[i][m] = false;
    }
    else
    {
        g_Dp[i][m] = Solve(A, i + 1, m - A[i]) || Solve(A, i + 1, m);
    }

    return g_Dp[i][m];
}

int main2()
{
    int A[MAX_N];        // 数列A
    int q;               // 整数mの個数
    int m[MAX_Q];        // q個の整数m
    
    
    for (int i = 0; i < MAX_Q; i++)
    {
        for (int j = 0; j < MAX_M; j++)
        {
            g_Dp[i][j] = -1;
        }
    }

    // 入力
    cin >> g_N;
    for (int i = 0; i < g_N; i++)
    {
        cin >> A[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }

    // 計算
    for (int i = 0; i < q; i++)
    {
        bool ans = Solve(A, 0, m[i]);
        cout << (ans? "yes": "no") << endl;
    }

    return 0;
}