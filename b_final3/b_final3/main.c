#include <stdio.h>
#define STUDENT  (10)   /* 生徒数 */
#define NAME_LEN (15)   /* 名前の文字数 */

int main(void)
{
    int score[STUDENT][8];              /* 8は国語数学英語合計と各順位の配列 */
    char name[STUDENT][NAME_LEN + 1];   /* 名前の格納配列 */
    int i, j, k, temp;
    
    /* 入力と初期化 */
    for (i = 0; STUDENT > i; i++) {
        printf("%d人目の名前を入力してください\n", i + 1);
        scanf("%s", &name[i][NAME_LEN + 1]);
        printf("%d人目の国語の点数を入力してください\n", i + 1);
        scanf("%d", &score[i][0]);
        printf("%d人目の数学の点数を入力してください\n", i + 1);
        scanf("%d", &score[i][1]);
        printf("%d人目の英語の点数を入力してください\n", i + 1);
        scanf("%d", &score[i][2]);
        score[i][3] = score[i][0] + score[i][1] + score[i][2];  /* 合計点数 */
        for (j = 4; 8 > j; j++) {
            score[i][j] = 1;     /* 国,数,英,合計の全順位を1で初期化 */
        }
    }
    
    /* 順位付け */
    for (i = 0; STUDENT - 1 > i; i++) {
        for (j = i + 1; STUDENT > j; j++) { /* 同点の場合 */
            for (k = 0; 4 > k; k++) {   /* 国数英合計の各点数 */
                if (score[i][k] < score[j][k]) {    /* 前後生徒の点数を比較 */
                    score[i][k + 4] = score[i][k + 4] + 1;  /* 順位を1つ下げる */
                }
            }
        }
    }
    
    /* バブルソート(昇順) */
    for (i = STUDENT - 1; 0 < i; i--) {
        for (j = 0; i > j; j++) {
            if (score[j][3] < score[j + 1][3]) {    /* 合計点数を比較 */
                for (k = 0; 8 > k; k++) {   /* 点数の入れ替え */
                    temp = score[j][k];
                    score[j][k] = score[j + 1][k];
                    score[j + 1][k] = temp;
                }
                for (k = 0; NAME_LEN > k; k++) {
                    <#statements#>
                }
            }
            
        }
    }
    
    /* 生徒のテスト結果表示 */
    printf("No Name            Kokugo  Sugaku  Eigo    Goukei\n");
    printf("---------------------------------------------------\n");
    for (i = 0; STUDENT > i; i++) {
        printf("%2d ", i + 1);      /* 番号 */
        printf("%-15s ", name[i]);  /* 名前 */
        for (j = 0; 8 > j; j++) {   /* 国語,数学,英語,合計 */
            printf("%3d[%2d] ", score[i][j], score[i][j + 4]);
        }
        printf("\n");
    }
    
    return 0;
}
