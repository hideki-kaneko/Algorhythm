#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D&lang=jp

// 最大積載量Pが与えられた時、全トラックで積める荷物の最大数を返します。
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

// 二分探索で、maxN >= n となる最小のpを求めます
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
    
    int n;        // 荷物の数
    int k;        // トラックの数
    int w[100000]; // 荷物の重さ

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int p = BinarySearch(n, k, w);
    
    cout << p << endl;

    return 0;
}