/* Sobel laplacianフィルタ LaplacianPGM.c */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"pgmppmio.h"

void spacial_filter()
/* 画像の空間フィルタリングを行う．                     */
/* Sobelフィルタ（水平方向微分）                        */
/* 原画像 gimage_in[y][x] ===> 変換後の画像 gimage_out[y][x]   */
{
    /* 適用するフィルタの定義（Sobel水平方向微分) */
    int weight[3][3] = {
        { 1,  1, 1 },
        { 1, -8, 1 },
        { 1,  1, 1 } };
    double div_const = 1.0; /* <== 最後に割る値 */
    double pixel_value; /* 計算値 */
    double min, max; /* 計算値の最小値，最大値 */
    int x, y, i, j;  /* ループ変数 */

    /* フィルタリング後の階調値の最小値，最大値を求める */
    printf("原画像にSobelフィルタ（水平方向微分）を施します．\n");
    min = (double)INT_MAX;
    max = (double)INT_MIN;
    for (y = 1; y < y_size1 - 1; y++) {
        for (x = 1; x < x_size1 - 1; x++) {
            pixel_value = 0.0;
            for (i = -1; i < 2; i++) {
                for (j = -1; j < 2; j++) {
                    pixel_value = pixel_value + weight[i + 1][j + 1] * gimage_in[y + i][x + j];
                }
            }
            pixel_value = pixel_value / div_const;
            if (pixel_value < min) min = pixel_value;
            if (pixel_value > max) max = pixel_value;
        }
    }
    if ((int)(max - min) == 0) exit(1);

    /* gimage_out[y][x] の初期化(外郭の画素のため）*/
    x_size2 = x_size1;
    y_size2 = y_size1;
    for (y = 0; y < y_size2; y++) {
        for (x = 0; x < x_size2; x++) {
            gimage_out[y][x] = 0;
        }
    }

    /* 処理後の値を線形変換してから gimage_out に代入 */
    for (y = 1; y < y_size1 - 1; y++) {
        for (x = 1; x < x_size1 - 1; x++) {
            pixel_value = 0.0;
            for (i = -1; i < 2; i++) {
                for (j = -1; j < 2; j++) {
                    pixel_value = pixel_value + weight[i + 1][j + 1] * gimage_in[y + i][x + j];
                }
            }
            pixel_value = pixel_value / div_const;
            pixel_value = MAX_BRIGHTNESS / (max - min) * (pixel_value - min);
            gimage_out[y][x] = (unsigned char)pixel_value;
        }
    }
}

main()
{
    load_image_pgm();    /* 画像データを gimage_in に読み込む */
    spacial_filter(); /* gimage_in にsobelフィルタ（水平方向微分）を施し gimage_out へ */
    save_image_pgm();    /* gimage_out を保存する */
    return 0;
}
