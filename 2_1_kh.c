#include <stdio.h>


void k2(void) {
	int x, i = 1, tmp;
	double ave = 0;
	printf("整数 %d:", i);
	scanf("%d", &x);
	ave += (double)x;
	tmp = x;
	i++;
	for (; i <= 4; i++) {
		printf("整数 %d:", i);
		scanf("%d", &x);
		ave += (double)x;
		tmp = tmp < x ? tmp : x;
	}
	ave = ave / 4;
	printf("平均値は%.2fです。\n", ave);
	printf("最小値は%dです。\n", tmp);
}

void k3(void) {
	char c;
	printf("Please Enter wsad.\n");
	c = getchar();
	switch (c)
	{
	case 'w':
		printf("Go Forward ↑");
		break;
	case 's':
		printf("Go Back ↓");
		break;
	case 'a':
		printf("Go Left ←");
		break;
	case 'd':
		printf("Go Right →");
		break;
	default:
		printf("Stay ・");
		break;
	}
}

void h1() {
	int tmp;
	char st[2][5] = { "偶数\0", "奇数\0" };
	printf("0～100\n");
	scanf("%d", &tmp);
	if (tmp >= 0 && tmp <= 100) {
		printf("入力値は正しいです。%sです。\n", st[tmp % 2]);
	}
	else {
		printf("入力値は正しくないです。\n");
	}
}

void main() {
	k2();
	k3();
	h1();
}