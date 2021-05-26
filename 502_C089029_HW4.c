#include <stdio.h>

void main()
{
	char one[100] = { 0, };
	char two[100] = { 0, };

	int one_bit[100] = { 0, };
	int two_bit[100] = { 0, };
	int result[100] = { 0, };

	printf("Please, type the 1st 5-bit Binary number: ");
	scanf("%s", one);

	printf("Please, type the 2nd 5-bit Binary number: ");
	scanf("%s", two);

	int j = 0;
	int g = 0;
	
	
	//문자열로 받아진 숫자를 숫자로 배열에 넣음

	while (one[j] != NULL)
	{
		one_bit[j] = one[j];
		j++;
	}
	while (two[g] != NULL)
	{
		two_bit[g] = two[g];
		g++;
	}

	int i = 0;
	int h = 0;

	//문자열을 숫자로 배열에 넣으면 아스키코드의 
	//숫자로 넣어지기때문에 -48해줘서 숫자로 만들기

	while (one_bit[i] != NULL)
	{
		one_bit[i] = one_bit[i] - 48;
		i++;
	}
	
	while (two_bit[h] != NULL)
	{
		two_bit[h] = two_bit[h] - 48;
		h++;
	}

	i = 0;
	h = 0;

	//임시로 저장할 공간
	int num = 0;
	int num2 = 0;

	//2~6번째 사진

	for (int k = 0; k <= 4; k++) 
	{
		num = one_bit[k] * two_bit[4];
		num2 = num2 + num;
		
		if (k == 1)
		{
			num = one_bit[k-1] * two_bit[4-k];
			num2 = num2 + num;
		}
		else if (k == 2)
		{
			num = one_bit[k - 1] * two_bit[3];
			num2 = num2 + num;
			num = one_bit[k - 2] * two_bit[4 - k];
			num2 = num2 + num;
		}
		else if (k == 3)
		{
			num = one_bit[k - 1] * two_bit[3];
			num2 = num2 + num;
			num = one_bit[k - 2] * two_bit[2];
			num2 = num2 + num;
			num = one_bit[k - 3] * two_bit[4 - k];
			num2 = num2 + num;
		}
		else if (k == 4)
		{
			num = one_bit[k - 1] * two_bit[3];
			num2 = num2 + num;
			num = one_bit[k - 2] * two_bit[2];
			num2 = num2 + num;
			num = one_bit[k - 3] * two_bit[1];
			num2 = num2 + num;
			num = one_bit[k - 4] * two_bit[0];
			num2 = num2 + num;
		}
		
		result[k+1] = num2;  //0 
		num2 = 0;		
	}

	//7~10번째 사진

	for (int k = 6; k <= 9 ; k++)
	{
		if (k == 6)
		{
			num = one_bit[k - 5] * two_bit[5 - k];
			num2 = num2 + num;
			num = one_bit[k -4] * two_bit[1];
			num2 = num2 + num;
			num = one_bit[k -3] * two_bit[2];
			num2 = num2 + num;
			num = one_bit[4] * two_bit[3];
			num2 = num2 + num;
		}
		else if (k == 7)
		{
			num = one_bit[k - 5] * two_bit[0];
			num2 = num2 + num;
			num = one_bit[k - 4] * two_bit[1];
			num2 = num2 + num;
			num = one_bit[4] * two_bit[2];
			num2 = num2 + num;
		}
		else if (k == 8)
		{
			num = one_bit[k-5] * two_bit[0];
			num2 = num2 + num;
			num = one_bit[4] * two_bit[1];
			num2 = num2 + num;
		}
		else if (k == 9)
		{
			num = one_bit[4] * two_bit[0];
			num2 = num2 + num;
		}

		result[k] = num2;  //0 
		num2 = 0;
	}

	int u = 0;
	result[0] = 0;
	result[10] = 0;

	//result 출력
	printf("The results is : ");
	while (u != 11)
	{
		printf("%d ", result[u]);
		u++;
	}

	
	



	
}