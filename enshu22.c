/* モノクロ画像の輝度を一定値変化させるプログラム changebright_pgm.c */
#include<stdio.h>
#include<stdlib.h>
#include"pgmppmio.h"

void change_bright()
/* 原画像 gimage_in の輝度を一定値変化させ gimage_out に代入する */
{
    /* ①変化させる輝度値を代入する変数br1 */
    /* 　輝度値の加算が255を超える，0より小さくなる場合の処理で必要な変数br2 */
    int x, y, br1, br2;    /* 制御変数 */

    printf("-----------------------------------------------------\n");
    printf("画像の輝度を変化させます．変化値（-255～255）を入力してください．\n");
    /* ②キーボードから変化させる輝度値を変数br1に代入 */
    scanf("%d", &br1);    /* 変化する輝度値br1を入力　*/

    /* 出力画像サイズ←入力画像サイズ */
    x_size2 = x_size1;  /* 横画素数 */
    y_size2 = y_size1;  /* 縦画素数 */

    /* ラスタ走査でgimage_inの輝度を一定値変化させてgimage_outに格納 */
    for (y = 0; y < y_size2; y++) {
        for (x = 0; x < x_size2; x++) {
            /* ③int型にキャストしてgimage_in[y][x]の値とbr1の値を加算しbr2に代入 */
            /* 　unsigned char は8ビット符号無しなので，int型で判定する必要あり */
            /* 　br2が255を超える場合はbr2に255を代入，0より小さい場合は0を代入 */
            /* 　br2を unsigned char にキャストしてgimage_out[y][x]に代入 */
            br2 = (int)gimage_in[y][x] + br1;
            if (br2 > MAX_BRIGHTNESS) {
                br2 = MAX_BRIGHTNESS;
            }
            else if (br2 < 0)
            {
                br2 = 0;
            }
            gimage_out[y][x] = (unsigned char)br2;
        }
    }
}

main()
{
    load_image_pgm();    /* 画像データを gimage_in に読み込む */
    change_bright(); /* gimage_in の輝度を一定値変化させ gimage_out へ */
    save_image_pgm();    /* gimage_out を保存する */
    return 0;
}
