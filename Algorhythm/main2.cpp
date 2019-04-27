#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp

#define MAX_N 20
#define MAX_Q 200

namespace{
int g_N; // ����Ano����
}

// ����g_N�̐���A�̗v�f�𑫂���m������ꍇTrue��Ԃ��܂�
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
    bool a1 = Solve(A, i + 1, m - A[i]);  // i�Ԗڂ̐����g��
    bool a2 = Solve(A, i + 1, m);         // �g��Ȃ�
    return (a1 || a2);
}

int main2()
{
    int A[MAX_N];  // ����A
    int q;         // ����m�̌�
    int m[MAX_Q];  // q�̐���m

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