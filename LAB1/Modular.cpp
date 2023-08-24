#include <iostream>
using namespace std;

struct Vector
{
  int*m_pVect=nullptr;
  int m_nCount=0;
  int m_nMax=0; 
  const int m_nDelta=10; 
};

void Resize(Vector *pThis)
{
    int *pTemp = new int[pThis->m_nMax + pThis->m_nDelta];
    for (int i = 0; i < pThis->m_nMax; i++)
        pTemp[i] = pThis->m_pVect[i];
    delete[] pThis->m_pVect;
    pThis->m_pVect = pTemp;
    pThis->m_nMax += pThis->m_nDelta;
}

/*void Resize(Vector *pThis)
{
pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) *(pThis->m_nMax + pThis->m_nDelta));
pThis->m_nMax += pThis->m_nDelta;
}*/

void Insert(Vector *pThis, int elem)
{
  if( pThis->m_nCount == pThis->m_nMax ) 
    Resize(pThis); 
  pThis->m_pVect[pThis->m_nCount++] = elem;
}



int main()
{
    Vector S;


    for (int n = 0; n < 100; n++)
    {
        Insert(&S, n);
    }

    for (int i = 0; i < S.m_nCount; i++)
    {
        cout << S.m_pVect[i] << ", ";
    }

    return 0;
}
