#include <iostream>
using namespace std;

int *gpVect = nullptr;
int gnCount = 0;
int gnMax = 0;

void Resize()
{
    const int delta = 10;
    int *pTemp = new int[gnMax + delta];
    for (int i = 0; i < gnMax; i++)
        pTemp[i] = gpVect[i];
    delete[] gpVect;
    gpVect = pTemp;
    gnMax += delta;
}

void Insert(int elem)
{
    if (gnCount == gnMax)
        Resize();
    gpVect[gnCount++] = elem;
}

int main()
{
    for (int n = 0; n < 100; n++)
    {
        Insert(n);
    }

    for (int i = 0; i < gnCount; i++)
    {
        cout << gpVect[i] << ", ";
    }

    return 0;
}

