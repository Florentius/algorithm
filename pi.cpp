#include <iostream>

#define INF = 987654321;

using namespace std;

string N;
int cache[10002];

int calculate(int begin)
{
  if(begin == N.size()) return 0;
  int& ret = cache[begin];
  if(ret != -1) return ret;
  
  
}

int main(void)
{
  int test_case;
  cin >> test_case;
  if (test_case < 0 || test_case>50)
    exit(-1);

  for (int i = 0; i < test_case; i++)
    {
	  for(int j = 0; j < 10002; j++)
		cache[j] = -1;
      cin >> N;
      cout << N << endl;
    }
  return 0;
}
