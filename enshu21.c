/* カラーが像を反転させるプログラム InversePPM.c */
#include<stdio.h>
#include<stdlib.h>
#include"pgmppmio.h"

void make_inverse_image()
/* 原画像 pimage_in を反転させて pimage_out に代入する */
{
    /* ①カラー画像配列pimage_in[k][y][x]の変数kを追加 */
    int x, y, k;    /* 制御変数 */

    printf("反転画像を作成します．\n");
    /* 出力画像サイズ←入力画像サイズ */
    x_size2 = x_size1;  /* 横画素数 */
    y_size2 = y_size1;  /* 縦画素数 */

    /* ラスタ走査でpimage_inの色値を反転させてpimage_outに格納 */
    for (y = 0; y < y_size2; y++) {
        for (x = 0; x < x_size2; x++) {
            /* ② forループでkを変化させ，pimage_in[k][y][x]の値を反転して，pimage_out[k][y][x]に代入 */
            for (k = 0; k < 3; k++) {
                pimage_out[k][y][x] = 255 - pimage_in[k][y][x];
            }
        }
    }
}

main()
{
    load_image_ppm();    /* 画像データを pimage_in に読み込む */
    make_inverse_image(); /* pimage_in を反転させ pimage_out へ */
    save_image_ppm();    /* pimage_out を保存する */
    return 0;
}
