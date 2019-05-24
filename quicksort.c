#include<stdio.h>


#define swap(a,b,c) (c=a, a=b, b=c)

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

		printf("left =%d, right =%d, low =%d, high =%d\n", left, right, low, high);
		for (int i=0; i<10; i++)
			printf("%d ",arr[i]);
		
		printf("\n");
	} while(low < high);

	swap(arr[left], arr[high], temp);
	return high;
}

void quick_sort(int arr[], int left, int right) {

	int q;

	if(left<right) {
		printf("\nquick_sort, left %d right %d\n", left, right);
		q = partition(arr, left, right);

		quick_sort(arr, left, q-1);
		quick_sort(arr, q+1, right);
	}
}

int main(void) {
  //int data[10] = { 10, 6, 7, 9, 3, 4, 2, 1, 5, 8 };
  //int data[10] = { 10, 6, 7, 2, 9, 1, 8, 3, 5, 4 };
  //int data[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int data[10] = {7,3,6,10,8,5,4,9,2,1};

  printf(" --정렬 전 순서--\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", data[i]);
  }
  printf("\n\n");

  quick_sort(data, 0, 9);

  printf(" --정렬 후 순서--\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
  return 0;
}
