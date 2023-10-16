#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second

int a[10][10]; int cnt;
bool markR[10][10], markC[10][10], markS[3][3][10];

bool check(int i, int j, int k)
{
  return (markR[i][k] == false) && (markC[j][k] == false) && (markS[i/3][j/3][k] == false);
}

void back(int i, int j)
{
  if(a[i][j] != 0)
  {
    if(i == 8 && j == 8) ++cnt;
      else
      {
        if(j < 8) back(i,j+1);
        else back(i+1,0);
        //back(i,j);
      }
  }
  else
  {
    REP(k,1,9)
    {
      if(check(i,j,k))
      {
        markR[i][k] = true;
        markC[j][k] = true;
        markS[i/3][j/3][k] = true;
        if(i == 8 && j == 8) ++cnt;
        else
        {
          if(j < 8) back(i,j+1);
          else back(i+1,0);
          //back(i,j);
        }
        markR[i][k] = false;
        markC[j][k] = false;
        markS[i/3][j/3][k] = false;
      }
    }
  }
}
int main()
{
  REP(i,0,8)
  {
    REP(j,0,8)
    {
      scanf("%d",&a[i][j]);
      markR[i][a[i][j]] = true;
      markC[j][a[i][j]] = true;
      markS[i/3][j/3][a[i][j]] = true;
    }
  }
  back(0,0);
  printf("%d",cnt);
}
