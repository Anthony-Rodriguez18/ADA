#include <iostream>
using namespace std;

class CVector
{
  private:
    int *m_pVect; 
    int m_nCount;
    int m_nMax;
    int m_nDelta; 
    void Init(int m_nDelta); 
    void Resize(); 
  public:
    CVector(int Delta = 10)
    {
      m_nDelta = Delta;
      m_nCount = 0;
      m_nMax = Delta;
      m_pVect = new int[m_nMax];
    } 
    void Insert(int elem);
    int GetCount();
    int GetElement(int index);
};

void CVector:: Resize()
{
  const int delta = 10;
  int *pTemp = new int[m_nMax + m_nDelta];
  for (int i = 0; i < m_nMax; i++)
     pTemp[i] = m_pVect[i];
  delete[] m_pVect;
  m_pVect = pTemp;
  m_nMax += delta;
}

void CVector::Insert(int elem)
{
  if( m_nCount == m_nMax ) 
    Resize(); 
  m_pVect[m_nCount++] = elem; 
}

int CVector::GetCount()
{
    return m_nCount;
}

int CVector::GetElement(int index)
{
  return m_pVect[index];
}

int main()
{
    CVector S;

    for (int n = 0; n < 100; n++)
    {
        S.Insert(n);
    }

    for (int i = 0; i <S.GetCount(); i++)
    {
        cout << S.GetElement(i) << ", ";
    }

    return 0;
}
