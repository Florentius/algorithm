#include <stdio.h>

void reverse(char *str, char *result, int map[], int end)
{
	int one, two, three, four;
	int i, j;

	
	one = map[0];
	two = map[1];
	three = map[2];
	four = map[3];

	i = one;

	j = three;
	while(j < four)
	{
		result[i++] = str[j++];
	}

	j = four;
	while(j <= end)
	{
		result[i++] = str[j++];
	}

	j = one;
	while(j < two)
	{
		result[i++] = str[j++];
	}


	j = two;
	while(j<three)
	{
		result[i++] = str[j++];
	}

	i = one;
	while(i <= end)
	{
		str[i] = result[i];
		i++;
	}

	return ;
}

int decompress(char *str, char * result, int start, int count)
{
	int end = 0;;
	int i = 0;
	int map[4] = {0, };
	int curcount = 0;
	
	i = start;

	while(curcount < count)
	{
		if (str[i] == 'x')
		{
			int end;
			map[curcount++] = i;
			end = decompress(str, result,  i+1, 4);
			i = end;
		}
		
		else if(str[i] == 'w' || str[i] == 'b')
		{
			map[curcount++] = i++;
		}
	}

	end = i;

	if(start !=0)
		reverse(str, result, map, end-1);

	return end;
}

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char input[1000] = {0, };
		char result[1000] = {0, };
		scanf("%s", &input);
		decompress(input, result, 0, 1);
		printf("%s\n", input);
	}
	return 0;
}

