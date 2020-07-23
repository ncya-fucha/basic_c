#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DATA_NUM (10)

int GetRandNum(int min, int max);   /* プロトタイプ宣言 */

/* 最小値取得プログラム */
int main(void)
{
    int data[DATA_NUM]; /* テストデータ */
    int i = 0;          /* カウンタ */
    int min = 0;        /* 最小値 */
    
    /* データを作成 */
    srand((unsigned int)time(NULL));    /* 乱数を作成 */
    for (i = 0; DATA_NUM > i; i++) {
        data[i] = GetRandNum(1, 100);
    }
    /* 作成したデータを表示 */
    for (i = 0; DATA_NUM > i; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    /* 最小値を探索 */
    min = data[0];  /* 先頭データを最小値に代入 */
    for (i = 1; DATA_NUM > i; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    /* 結果を表示 */
    printf("最小値は%dです\n", min);
    
    return 0;
}

/* 指定した範囲の乱数作成関数 */
int GetRandNum(int min, int max)
{
    int range, num;
    range = (unsigned int)max - (unsigned int)min;  /* 算術オーバーフロー対策 */
    num = min + (int)(rand() * (range + 1.0) / (1.0 + RAND_MAX));
    
    return num;
}
