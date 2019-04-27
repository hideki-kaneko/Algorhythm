#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D&lang=jp

// �ő�ύڗ�P���^����ꂽ���A�S�g���b�N�Őς߂�ו��̍ő吔��Ԃ��܂��B
int GetMaxN(unsigned long p, int n, int k, const int* w)
{
    int wIndex = 0;

    for (int i = 0; i < k; i++)
    {
        int currentWeight = 0;
        while (currentWeight + w[wIndex] <= p)
        {
            currentWeight += w[wIndex];
            ++wIndex;
            if (wIndex == n)
            {
                return n;
            }
        }
    }
    return wIndex;
}

// �񕪒T���ŁAmaxN >= n �ƂȂ�ŏ���p�����߂܂�
int BinarySearch(int n, int k, const int* w)
{
    long int right = 100000 * 10000;
    long int left = 0;
    long int p = floor((right + left) / 2);

    while (left < right)
    {
        int maxN = GetMaxN(p, n, k, w);
        if (maxN >= n)
        {
            right = p;
        }
        else // maxN < n
        {
            left = p + 1;
        }
        p = floor((right + left) / 2);
    }
    return p;
}

int main1()
{    
    
    int n;        // �ו��̐�
    int k;        // �g���b�N�̐�
    int w[100000]; // �ו��̏d��

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int p = BinarySearch(n, k, w);
    
    cout << p << endl;

    return 0;
}