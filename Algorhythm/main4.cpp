#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=jp

#define N_MAX 100
#define C_MAX 101

int g_Cost[N_MAX + 1][N_MAX + 1];   // g_Cost[i][j]: (Mi*Mi+1*...Mj)�̌v�Z��
int g_C[C_MAX];                     // �e�s��̗�(g_C[0]:�ŏ��̍s��̍s�� g_C[n]:�s��n�̗�)

// (Mi*Mi+1*...Mj)�̌v�Z�񐔂����߂܂�
int CalcCost(int i, int j)
{
    assert(i > 0);
    if (g_Cost[i][j] != -1)     // �R�X�g���v�Z�ς݂̎�
    {
        return g_Cost[i][j];
    }
    else if (i == j)
    {
        g_Cost[i][j] = 0;
        return 0;               // �s��1�͌v�Z��0
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
    int n;            // �s��̐�
    int _c;           // ���͗p�_�~�[�ϐ�
    
    for (int i = 0; i < N_MAX + 1; i++)
    {
        for (int j = 0; j < N_MAX + 1; j++)
        {
            g_Cost[i][j] = -1;
        }
    }

    // ����
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

    //�v�Z
    int ans = CalcCost(1, n);
    cout << ans << endl;

    return 0;
}