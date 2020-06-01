/* 背景差分による画面合成のプログラム　BlendB2PGM.c */
#include<stdio.h>
#include"pgmppmio.h"
unsigned char gimage_work[10][MAX_IMAGESIZE][MAX_IMAGESIZE]; /* 複数の入力画像データを保存する3次元配列 */
int nimage;  /* 合成する（入力する）画像の枚数を格納する変数 */
int tlv; /* 前景か背景かを判断する閾値（注目画像と背景画像の差分値）を格納する変数 */

void blend()
/* 画像の合成を行う */
/* 背景画像gimage_work[0][y][x]と注目画像gimage_work[1][y][x]の輝度差に基づき合成画像作成 */
{
	int x, y, i;
	
	/* 出力画像サイズを設定 */
	x_size2 = x_size1;  /* 横画素数 */
	y_size2 = y_size1;  /* 縦画素数 */

	/* gimage_outの初期化 背景画像をコピー*/
	for ( y = 0; y < y_size2; y ++ ) {
		for ( x = 0; x < x_size2; x ++ ) {
			gimage_out[y][x] = gimage_work[0][y][x];
		}
	}

	/* ラスタ走査で各画素の輝度の差を計算して閾値と比較し，合成画像をgimage_out[y][x]に格納 */
	for ( y = 0; y < y_size2; y ++ ) {
		for ( x = 0; x < x_size2; x ++ ) {
			for ( i = 1; i < nimage; i++) {
				/* 注目画像と背景画像の輝度差の絶対値を計算しdifに格納 */
				int dif = gimage_work[i][y][x] - gimage_work[0][y][x];
				if (dif < 0) dif *= -1;
				/* ①　差の絶対値difと閾値tlvを比較 */
		    	/* 　　閾値より大きい→ 前景，　閾値以下→背景 */
		    	/* 　　前景ならばgimage_work[i][y][x]をgimage_out[y][x]に代入 */
				/* 　　プログラム作成 */
				if (dif > tlv)
					gimage_out[y][x] = gimage_work[i][y][x];
				
			}
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
		/* gimage_in[y][x]をgimage_work[i][y][x]に格納（コピー）する */
		for (y = 0; y < y_size1; y++) {
			for (x = 0; x < x_size1; x++) {
				gimage_work[i][y][x] = gimage_in[y][x];
			}
		}		
	}
	
	/* 前景か背景かを判断する閾値を変数tlvに格納する */
	printf("差分の閾値を入力してください\n");
	scanf("%d", &tlv);

	blend(); /* 合成画像を作成しgimage_outに格納 */
	save_image_pgm( ); /* gimage_outを保存する */
	return 0;
}
