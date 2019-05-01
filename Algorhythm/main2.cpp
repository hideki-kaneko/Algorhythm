#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp

#define MAX_N 20
#define MAX_Q 200
#define MAX_M 2000

namespace{
int g_N;               // ����A�̒���
int g_Dp[MAX_Q][MAX_M];// �v�Z���ʃ����p�z�� <-1:���v�Z 0:false 1:true>
}

// ����g_N�̐���A�́Ai�Ԗڈȍ~�̗v�f�𑫂���m������ꍇTrue��Ԃ��܂�
bool Solve(const int* A, int i, int m)
{
    if (m < 0)
    {
        return false;
    }
    else if (g_Dp[i][m] != -1)
    {
        return g_Dp[i][m]; // Solve(i, m)���v�Z�ς�
    }
    else if (m == 0)                          // m����ꂽ
    {
        g_Dp[i][m] = true;
    }
    else if (i >= g_N)                   // N�g���Ă�m�����Ȃ�����
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
    int A[MAX_N];        // ����A
    int q;               // ����m�̌�
    int m[MAX_Q];        // q�̐���m
    
    
    for (int i = 0; i < MAX_Q; i++)
    {
        for (int j = 0; j < MAX_M; j++)
        {
            g_Dp[i][j] = -1;
        }
    }

    // ����
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

    // �v�Z
    for (int i = 0; i < q; i++)
    {
        bool ans = Solve(A, 0, m[i]);
        cout << (ans? "yes": "no") << endl;
    }

    return 0;
}