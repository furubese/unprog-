/* 重み付け加算による画面合成のプログラム
   N枚(=<10)のモノクロ画像　BlendW1PGM.c */
#include<stdio.h>
#include<stdlib.h>
#include"pgmppmio.h"
unsigned char gimage_work[10][MAX_IMAGESIZE][MAX_IMAGESIZE]; /* 複数の入力画像データを保存する3次元配列 */
int nimage; /* 合成する（入力する）画像の枚数を格納する変数 */

void blend()
/* 画像の合成を行う */
/* 原画像(gimage_work[0][y][x] + gimage_work[1][y][x] + ...) * (1/n)
   -> 合成後の画像gimage_out[y][x] */
{
	int x, y, i;

	/* gimage_work[i][y][x]の合成 */
	x_size2 = x_size1;  /* 横画素数 */
	y_size2 = y_size1;  /* 縦画素数 */
	/* ラスタ走査で各画素の輝度の平均を計算し，gimage_out[y][x]に格納 */
	for ( y = 0; y < y_size2; y ++ ) {
		for ( x = 0; x < x_size2; x ++ ) {
			double a=0.0; /* 複数の入力画像における同じ位置(x, y)の画素の値の平均を計算する変数 */
			
			/* ②　gimage_work[i][y][x]を入力画像の枚数分，変数aに加算 */
			/* 　　加算終了後，変数aの値を変数nimageの値で除算して，gimage_out[y][x]に代入 */
			/* 　　プログラム作成 */	
			for (i = 0; i < nimage; i++) {
				a += (double)gimage_work[i][y][x];
			}
			gimage_out[y][x] = (unsigned char)(a / nimage);
			
		}
	}
}

main( )
{
	int x, y, i;

	/* 複数の画像データをgimage_work[i][y][x]に読み込む */
	printf("画像の枚数(2～10)を入力してください\n"); /* 画像の枚数を入力 */
	scanf("%d", &nimage);
	if ( nimage < 2 || nimage > 10) {
		printf("画像の枚数が2～10ではありません\n");
		exit(1);
	}
	for ( i = 0; i < nimage; i++) { /* 入力された枚数分，画像データを読み込む */
		load_image_pgm( ); /* 入力画像はgimage_in[y][x]に格納 */
				
		/* ①　gimage_in[y][x]をgimage_work[i][y][x]に格納（コピー）する */
		/* 　　プログラム作成 */
		for (y = 0; y < y_size1; y++) {
			for (x = 0; x < x_size1; x++) {
				gimage_work[i][y][x] = gimage_in[y][x];
			}
		}
		
	}

	blend();    /* gimage_workを合成してgimage_outへ */
	save_image_pgm( ); /* gimage_outを保存する */
	return 0;
}
