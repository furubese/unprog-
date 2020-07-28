#include <stdio.h>
#define you 7

int main() {
	int data[you] = { 9,-11,23,99,43,-55,5 };
	int i;
	float ave = 0;

	printf("データ：%d", data[0]);
	for (i = 1; i < you; i++) {
		printf(", %d", data[i]);
	}
	printf("\n");

	for (i = 0; i < you; i++) {
		ave += data[i];
	}
	ave = ave / (i);
	ave = ave * 100 / 100;
	if ((ave * 100) - (int)(ave * 100) >= 0.5) {
		ave = (float)((int)(ave * 100 + 5) / 100.0);
	}
	else {
		ave = (float)((int)(ave * 100) / 100.0);
	}
	printf("平均値：%.2f\n", ave);

	int max=you - 1, min=you - 1;
	for (i = 0; i < you -1; i++) {
		max = (data[max] < data[i]) ? i : max;
		min = (data[min] > data[i]) ? i : min;
	}
	printf("最大値：%d, 最大値の添字：%d\n", data[max], max);
	printf("最小値：%d, 最小値の添字：%d\n", data[min], min);

	int s, no;
	printf("検索したい数値：");
	scanf("%d", &s);

	int sss[you];

	for (i = 0; i < you; i++) {
		if (data[i] > s) {
			sss[i] = data[i] - s;
		}
		else {
			sss[i] = s - data[i];
		}
	}

	no = 0;
	for (i = 0; i < you; i++) {
		no = (sss[no] > sss[i]) ? i : no;
	}

	printf("%d番目の%dが一番近いです。", no + 1, data[no]);
}
