#include <iostream>
using namespace std;

int gVect[100]; 
int gnCount;

void Insert(int elem)
{
  if( gnCount < 100 )
  { gVect[gnCount] = elem;
  gnCount++;}
}

int main() {
  for(int n=0;n<100;n++)
  {  Insert(n);}

  for(int i=0;i<100;i++)
  {cout<<gVect[i]<<", ";}
}

