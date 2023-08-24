#include <iostream>
using namespace std;

template <typename Type> class CVector
{
private:
    Type *m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10)
    {
        m_nDelta = delta;
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new Type[m_nMax];
    }
    void Insert(Type elem);
    int GetCount();
    Type GetElement(Type index);
};

template <typename Type> void CVector<Type>::Resize()
{
    Type *pTemp = new Type[m_nMax + m_nDelta]; 
    for (int i = 0; i < m_nMax; i++)
        pTemp[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

template <typename Type> void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

template <typename Type> int CVector<Type>::GetCount()
{
    return m_nCount;
}

template <typename Type> Type CVector<Type>::GetElement(Type index)
{
    return m_pVect[index];
}

int main()
{
    CVector<int> S;

    for (int n = 0; n < 100; n++)
    {
        S.Insert(n);
    }

    for (int i = 0; i < S.GetCount(); i++)
    {
        cout << S.GetElement(i) << ", ";
    }

    return 0;
}
