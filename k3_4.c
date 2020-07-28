#include <stdio.h>
#include <stdio.h>
#define NUM 5

int main(void) {
    double temp[NUM];
    char city[NUM][20] = { "Okayama","Tottori","Matsue","Hiroshima","Yamaguchi" };
    double max;
    int max_index;
    int i;

    for (i = 0; i < NUM; i++) {
        printf("%sの今日の最高気温を入力：", city[i]);
        scanf("%lf", temp + i);
    }


    max_index = 0;
    max = temp[0];

    for (i = 1; i < NUM; i++) {
        if (max < temp[i]) {
            max = temp[i];
            max_index = max;
        }
    }
    printf("最高気温が一番高いのは%sの%.1fです。\n", city[max_index], max);
}