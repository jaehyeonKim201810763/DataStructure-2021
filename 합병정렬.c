# include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define MAX_SIZE 100
void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);

int main()
{
	int i;
	int j;
	int n = MAX_SIZE;
	int list[n];
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		list[i] = rand() % 300;
		for (j = 0; j < i; j++)
			if (list[i] == list[j]) {
				i--;
				break;
			}
	}
	printf("정렬 전 : \n ");
	for (i=0;i<n;i++)
        printf("%d ",list[i]);
    printf("\n"); 
	printf("정렬 후 : \n ");
    merge_sort(list, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //분할
		merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬
		merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬
		merge(list, left, mid, right); // 결합
	}
}
void merge(int list[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left, l;
	int sorted[MAX_SIZE];

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}