#include <iostream>

using namespace std;
const int MOD = 1000000007;

int N;
int cache[101] = {0, };

int tiling(int N)
{

  if(N <=1 ) return 1;

  int &ret = cache[N];

  if (ret != 0)
    return ret;
  
  return ((tiling(N-1) + tiling(N-2)) % MOD);
}

int main()
{
  int T;

  cin >> T;

  for(int i=0; i<T; i++)
    {
      cin >> N;
      int ret = tiling(N);
      cout << ret << endl;
    }
}
