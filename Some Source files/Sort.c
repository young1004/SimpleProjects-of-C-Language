#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
비교함수를 갖는 삽입정렬 함수(라이브러리 함수 qsort 따라 하기)
@param		a : 배열 시작 주소
@param		n : 배열의 원소의 수
@param	 size : 각 원소의 바이트 수
@param cmpare : 정렬에 사용할 비교함수 포인터
*/
void insertion_sort(void *a, int n, int size, int(*cmp)(const void *a, const void *b))
{
	int i, j;
	void *key = malloc(size);

	for (i = 0; i < n; i++)
	{

		memcpy(key, (char *)a + i * size, size);//key = a[i];

		j = i - 1;
		while (j >= 0 && cmp((char *)a + j * size, key) > 0)
		{
			memcpy((char *)a + (j + 1) * size, (char *)a + j * size, size);//a[i + 1] = a[i];
			j--;

		}
		memcpy((char *)a + (j + 1) * size, key, size);//a[j + 1] = key;
	}

	free(key);

}


//정수를 오름차순으로 정렬하는 비교함수
int asc_compare(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	
	if (*x < *y) return -1;
	if (*x > *y) return 1;

	return 0;

}

//정수를 내림차순으로 정렬하는 비교함수
int des_compare(const void *a, const void *b)
{
	return -asc_compare(a, b);
}

//문자열을 정렬하는 비교함수
int str_asc_compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int str_des_compare(const void *a, const void *b)
{
	return -strcmp((char *)a, (char *)b);
}

int main(void)
{
	int a[5] = { 5, 2, 7, 1, 3 };
	char animals[4][20] = { "dog", "cat", "lion", "bat" };
	int i;

	insertion_sort(a, 5, sizeof(int), des_compare);

	for (i = 0; i < 5; i++)
		printf("%d", a[i]);

	printf("\n\n");

	qsort(animals, 4, 20, str_des_compare);

	for (i = 0; i < 4; i++)
		printf("%s ", animals[i]);
}

/*
int *a = (int *)x;
배열을 받을 때, const void *로 파라미터를 받으면 좀더 명확한 프로그래밍을 할 수있음.
*/