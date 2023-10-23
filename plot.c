#include<stdio.h>

int main()
{
    FILE *fp;
    int chk;
    char c;

    // 実行ファイルと同じディレクトリにある「test.txt」を開く
    fp = fopen("test.txt", "r");  
    if(fp == NULL)  // ファイルがオープンできない場合
    {
        fprintf(stderr, "ファイルオープンエラー\n");
        return 1;
    }
    printf("moved1");
    // ファイルから1バイトずつ読み込んで1バイトずつ標準出力する
    while(1)
    {
        c = fgetc(fp);  // ファイルから1バイト読み込む

        printf("%c",c);
        if(feof(fp))  // ファイル終端の場合
        {
            printf("moved5");
            break;  // ループを抜ける
        }

        if(ferror(fp))  // 入力ストリームエラーの場合
        {
            fprintf(stderr, "ストリームエラーです\n");
            break;
        }

        printf("%c",c);  // 1バイト標準出力
        printf("moved3");
    }

    // カレントディレクトリにある「test.txt」を閉じる
    chk = fclose(fp);
    if(chk != 0)  // ファイルクローズ失敗
    {
        fprintf(stderr, "ファイルクローズエラー\n");
        return 1;
    }

    return 0;
}