#include <stdio.h>

int analysis_member(char *member, int *result, int *total)
{
	int i = 0;
	int j = 0;
	while (member[i] != '\0')
	{
		if(member[i] == 'M')
		{
			result[j] = i;
			j++;
			member[i] = 1;
		}
		else {
			member[i] = 0;
		}
		i++;
	}
	*total = i;
	return j;
}

int analysis_fan(char *fan, int *result, int *total)
{
	int i = 0;
	while (fan[i] != '\0')
	{
		if(fan[i] == 'M')
		{
			fan[i] = 1;
		}
		else
		{
			fan[i] = 0;
		}
		i++;
	}
	*total = i;
}


int calculate(char *member, char *fan, int *result, int man_total, int member_total,  int fan_total)
{
	int i = 0;
	int ret = 0;

	
	while(i<= (fan_total - member_total))
	{
		int j = 0;
		int temp = 0;
		while(j < man_total)
		{
			if(fan[i+result[j]] & member[result[j]])
			{
			   break;
			}
			if(j == (man_total -1))
			{
				ret ++;
			}
			j++;
		}
		i++;
	}

	return ret;
}

int main()
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char member_char[200000] = {0, };
		char fan_char[200000] = {0, };
		int result[200000] = {0, };
		int ret;
		int man_total;
		int member_total;
		int fan_total;

		ret = scanf("%s", member);
		ret = scanf("%s", fan);

		man_total = analysis_member(member, result, &member_total);
		analysis_fan(fan, result, &fan_total);

		ret = calculate(member, fan, result, man_total, member_total, fan_total);
		printf("%d\n", ret);
	}
	return 0;


}
