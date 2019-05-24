#include <iostream>

using namespace std;

int N,S;
int V[100];

int main()
{
  int text_case;
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
      for(int j=0; j<N; j++)
	cin >> V[j];
    }
  return 0;

}
