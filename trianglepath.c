#include <stdio.h>

int getmax(int a, int b)
{
	if(a >b)
		return a;
	else
		return b;
}

int get_max_value(int triangle[100][100], int max[100][100], int triangle_size, int i, int j)
{
	int max_value;
	if((i<0) || (j<0)) {
		return -1;
	}
	if(j > i) {
		return -1;
	}
	if(max[i][j] > 0)
	{
		max_value = max[i][j];
	}
	else {
		max[i][j] = (triangle[i][j] + getmax(get_max_value(triangle, max, triangle_size, i-1, j), get_max_value(triangle, max, triangle_size,  i-1, j-1)));
	}
	return max[i][j];
}
int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int triangle_size = 0;
		int i = 0, j = 0;
		int triangle[100][100] = {0, };
		int max[100][100] = {0, };
		int max_value = 0;
		int tmp;			

		scanf("%d", &triangle_size);
		
		for (i = 0; i<triangle_size; i++)
		{
			for(j = 0; j<= i; j++)
			{
				scanf("%d", &triangle[i][j]);
			}
		}

		max[0][0] = triangle[0][0];
		i = triangle_size - 1;
		
		for (j = 0; j < triangle_size; j++)
		{
			tmp = get_max_value(triangle, max, triangle_size, i, j);
			
			if(tmp > max_value)
			{
				max_value = tmp;
			}
		}
		printf("%d\n", max_value);
	}
	return 0;
}

