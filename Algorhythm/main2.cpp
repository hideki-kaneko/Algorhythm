#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp

#define MAX_N 20
#define MAX_Q 200

namespace{
int g_N; // 数列Ano長さ
}

// 長さg_Nの数列Aの要素を足してmが作れる場合Trueを返します
bool Solve(const int* A, int i, int m)
{
    if (m == 0)
    {
        return true;
    }
    if (i >= g_N && m != 0)
    {
        return false;
    }
    bool a1 = Solve(A, i + 1, m - A[i]);  // i番目の数を使う
    bool a2 = Solve(A, i + 1, m);         // 使わない
    return (a1 || a2);
}

int main2()
{
    int A[MAX_N];  // 数列A
    int q;         // 整数mの個数
    int m[MAX_Q];  // q個の整数m

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