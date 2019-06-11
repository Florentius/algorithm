#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321;

int N,S;
int V[101];

int cache[101][11];

int min (int a, int b)
{
  if (a<b)
    return a;
  else
    return b;
}

int minError(int lo, int hi)
{
  return 0;
}
int quantize(int from, int parts)
{
  if(from == N)
    return 0;
  if(parts ==0)
    return INF;

  int &ret = cache[from][parts];
  if (ret != -1)
    return ret;

  ret = INF;
  for(int partSize =1; from+partSize <= N; ++partSize)
    {
      ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1);
    }
}
int main()
{
  int test_case;
  cin >> test_case;

  if (test_case < 0 || test_case>50)
    exit(-1);

  for (int i = 0; i < test_case; i++)
    {
      memset(cache, -1, sizeof(cache));
      cin >> N >> S;
      if(N > 100 || N < 1)
	exit(-1);
      if(S>10 || S < 1)
	exit(-1);
      for(int j=1; j<=N; j++)
	cin >> V[j];

      quantize(1, S);
    }
  return 0;

}
