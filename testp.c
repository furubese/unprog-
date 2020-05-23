﻿#include<stdio.h>
#include<stdlib.h>

main()
{
    int x, y, k; /* ループ変数 */
    char file_name[1024]; /* ファイル名用の文字配列 */
    FILE* fp; /* ファイルポインタ */
    int x_size2 = 20; /* 横画素数 */
    int y_size2 = 20; /* 縦画素数 */
    unsigned char pimage_out[3][20][20] =
    {
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* R面の値 */
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ,
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 },
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 },
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 },
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 },
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 },
            { 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0 }
        },
        {
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0}, /* G面の値 */
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0}
        },
        {
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0}, /* B面の値 */
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0}
        }
    };

    /* 出力ファイルのオープン */
    printf("-----------------------------------------------------\n");
    printf(" カラー階調画像（ppm形式）出力ルーチン\n");
    printf("-----------------------------------------------------\n");
    printf("出力ファイル名 (*.ppm) : ");
    scanf("%s", file_name);
    fp = fopen(file_name, "wb");

    /* ヘッダ情報を出力 */
    fputs("P6\n", fp);
    /* # で始まるコメント行（省略可能） */
    fputs("# Created by ImgProc\n", fp);
    /* 画像の横幅，縦幅の出力 */
    fprintf(fp, "%d %d\n", x_size2, y_size2);
    /* 最大階調値の出力 */
    fprintf(fp, "%d\n", 255);

    /* 画像データの出力 */
    for (y = 0; y < y_size2; y++) {
        for (x = 0; x < x_size2; x++) {
            for (k = 0; k < 3; k++) {
                fputc(pimage_out[k][y][x], fp);
            }
        }
    }
    printf("データは正しく出力されました．\n");
    printf("-----------------------------------------------------\n");
    fclose(fp);
    return 0;
}
