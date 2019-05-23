#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

 
const long long NEGINF = numeric_limits<long long>::min();

int A[100], B[100];
int cache[101][101];
int A_size, B_size;

int jlis(int aIdx, int bIdx)
{
  int &result = cache[aIdx + 1][bIdx + 1];
  if (result != -1)
    return result;

  result = 0;
  long long a = (aIdx == -1 ? NEGINF : A[aIdx]);
  long long b = (bIdx == -1 ? NEGINF : B[bIdx]);

  long long maxElement = max(a, b);

  for (int nextA = aIdx + 1; nextA < A_size; nextA++)
    if (maxElement < A[nextA])
      result = max(result, jlis(nextA, bIdx) + 1);
  for (int nextB = bIdx + 1; nextB < B_size; nextB++)
    if (maxElement < B[nextB])
      result = max(result, jlis(aIdx, nextB) + 1);
  return result;
}

int main(void)
{
  int test_case;
  cin >> test_case;
  if (test_case < 0 || test_case>50)
    exit(-1);

  for (int i = 0; i < test_case; i++)
    {
      memset(cache, -1, sizeof(cache));
      cin >> A_size >> B_size;
      if (A_size > 100 || B_size > 100 || A_size < 1 || B_size < 1)
	exit(-1);
      for (int j = 0; j < A_size; j++)
	cin >> A[j];
      for (int j = 0; j < B_size; j++)
	cin >> B[j];
      cout << jlis(-1, -1) << endl << endl;
    }
  return 0;
}

