#include <stdio.h>

int main(void) {
	int data[4];
	int i, j, tmp;
	for (i = 0; i < 4; i++) {
		printf("整数%d：",i + 1);
		scanf("%d", data + i);
	}

	for (i = 0; i < 4 - 1; i++) {
		for (j = 4- 1; j > i; j--) {
			if (data[j - 1] > data[j]) {
				tmp = data[j-1];
				data[j-1] = data[j];
				data[j] = tmp;
			}
		}
	}

	printf("入力した値を小さい順にソートしました：");
	for (i = 0; i < 4; i++) {
		printf("%d ", data[i]);
	}
	printf("\n")
	return 0;
}