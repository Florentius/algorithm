#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321;
#define swap(a,b,c) (c=a, a=b, b=c)

int N,S;

int cache[101][11];
int V[101], pSum[101], pSqSum[101];

int min (int a, int b)
{
  if (a<b)
    return a;
  else
    return b;
}

int partition(int arr[], int left, int right) {
	int low,high,pivot,temp;
	low=left;
	high=right;
	pivot = arr[left];

	low++;
	
	do {
		while(low < right && arr[low] < pivot)
			low++;
		while(high > left && arr[high] > pivot)
			high--;

		if(low<high){
			swap(arr[low],arr[high],temp);
		}
	} while(low < high);

	swap(arr[left], arr[high], temp);
	return high;
}

void quick_sort(int arr[], int left, int right) {

	int q;

	if(left<right) {
		q = partition(arr, left, right);

		quick_sort(arr, left, q-1);
		quick_sort(arr, q+1, right);
	}
}

void precalc() {
  quick_sort(V, 0, N-1);
			
  pSum[0] = V[0];
  pSqSum[0] = V[0] * V[0];
  for(int i=1; i<N; i++)
    {
      pSum[i] = pSum[i-1] + V[i];
      pSqSum[i] = pSqSum[i-1] + (V[i] * V[i]);
    }
}

int minError(int lo, int hi)
{
  int sum = pSum[hi] - ((lo == 0)? 0 : pSum[lo-1]);
  int sqSum = pSqSum[hi] - ((lo == 0)? 0 : pSqSum[lo-1]);

  int m = int(0.5 + (double)sum / (hi - lo + 1));
  int ret = sqSum - (2*m*sum) + (m*m*(hi-lo+1));
  return ret;
}

int quantize(int from, int parts)
{
  if(from >= N)
    return 0;
  
  if(parts == 0)
    return INF;

  int &ret = cache[from][parts];
  if (ret != -1)
    return ret;

  ret = INF;
  for(int partSize =1; from+partSize <= N; ++partSize)
    {
      ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
    }

  return ret;
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
      for(int j=0; j<N; j++)
		cin >> V[j];

	  precalc();
	  cout << quantize(0, S) << endl;
	  
    }
  return 0;

}
