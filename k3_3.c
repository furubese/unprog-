#include <stdio.h>

int main(void) {
	char name[30];
	int i, c;
	printf("キーボードから自分の名前をアルファベットで入力して下さい：");
	scanf("%s", name);


	i = 0;
	c = 0;
	while (name[i] != '\0') {
		if (name[i] == 'a' || name[i] == 'u'|| name[i] == 'A' || name[i] == 'U') {
			c += 1;
		}
		i++;
	}
	printf("%sという名前の長さは%d文字です。\n", name, i);

	char name_rev[30];
	int j;
	for (j = 0; j < i; j++) {
		name_rev[j] = name[i - j - 1];
	}
	name_rev[j] = '\0';
	printf("%sの逆順は%sです。\n", name, name_rev);
	printf("%sに含まれるa(A)とu(U)は%d文字です。\n", name, c);


	return 0;
}
