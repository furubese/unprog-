/* カラー画像を90°回転させるプログラム ReverseVPPM.c */
#include<stdio.h>
#include<stdlib.h>
#include"pgmppmio.h"

void reverse()
/* 原画像 pimage_in の画素を左右反転させ pimage_out に代入する */
{
    int x, y, k;    /* 制御変数 */

    printf("カラー画像を左右反転します．\n");
    /* 出力画像サイズ←入力画像サイズ */
    x_size2 = y_size1;  /* 横画素数 */
    y_size2 = x_size1;  /* 縦画素数 */

    /* ラスタ走査でgimage_inの画素を左右反転させてgimage_outに格納 */
    for (y = 0; y < y_size1; y++) {
        for (x = 0; x < x_size1; x++) {
            for (k = 0; k < 3; k++) {
                pimage_out[k][x_size1 - x][y] = (unsigned char)pimage_in[k][y][x];
            }
        }
    }
}

main()
{
    load_image_ppm();    /* 画像データを pimage_in に読み込む */
    reverse(); /* pimage_in の画素を左右反転させ pimage_out へ */
    save_image_ppm();    /* pimage_out を保存する */
    return 0;
}
