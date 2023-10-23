#include <stdio.h>		// おまじない（必要なのでいじらない)
#include <stdlib.h>		// おまじない（必要なのでいじらない）

// 「//」以降はコメント　プログラムには反映されない（コンピュータは読み込まない）


int main( void ){ 				// おまじない（必要なのでいじらない）ここ以降がプログラムの本体


///////////変数の宣言：計算式中で使用する文字は種類別にここで宣言する/////////
    int divt = 1600;
    int divx = 100;
	int 	i, j;				// 整数型
	double	temp[divx], newtemp[divx];	// 実数型（temp[0]からtemp[99]の合計100個の配列を用意）
	FILE *fp;				// 計算結果をファイルに出力するときに必要な変数
    double maxt = 4.6e9;
    double maxx = 6400; // delxが大きいということは、めちゃくちゃでかいということを表すので、ある程度小さくしないと熱伝導の効果は無視できてしまう。
    double alpha = 6.2409e-5; //地球の材質は花崗岩を想定　ケイ酸塩がほとんどだろうし妥当かも。 y, km に変換済み

    double delx = maxx/divx;
    double delt = maxt/divt;
    double a = delt * alpha /(delx*delx);
////////// 計算結果を書き込むファイル(例 "result.txt")を作成//////////////

	if ((fp=fopen("terra.txt","w")) == NULL){  // result.txtの部分は好きなファイル名に設定できる
		printf("Cannot open the file\n");
		exit(1);
	}


///////////// 初期条件の設定 ////////////////

	temp[divx-1] = 278.58 ;		// 境界条件：放射平衡温度
	for(i = 1; i<divx-1; i++)		// for:繰り返し命令　i=1:iが1からスタート　i<100:iが100より小さい間　i++:iを1つずつ追加して 
		temp[i] = 2000;	// その他の部分(temp[1]からtemp[99])の初期温度
/////////////////////////////////////////////
    printf("%lf \n ", alpha );

/////// 熱伝導方程式の計算（for文を使った繰り返し）//////

	for(j = 0; j < divt; j++){	//時間ステップの繰り返し j < ○○ の○○の値を増やせば計算時間を増やせる
        
		for(i = 1; i<divx-2; i++)
			newtemp[i] = a*((1/i+1)*temp[i+1] -2*temp[i] + (1-1/i)*temp[i-1]) + temp[i]; 	// 差分方程式

		for(i = 1; i<divx-2; i++)
			temp[i] = newtemp[i];				// 温度を次の時間ステップのものに更新する（いじらない）
		
		//境界条件
		temp[divx-1] = 278.58;					// 地球表面の温度の境界条件
		temp[0] = temp[1] ;				// 地球中心の断熱条件
		//出力部分
      if(j%5000 == 0){
            printf("%lf  %5.1f\n", j*delt, temp[90]);			//画面にjとtemp[10]を出力 %d→整数の表示　%f→実数の表示（5.1は全部で5桁，小数点以下1桁の意味）　\n→改行
            fprintf(fp, "%lf  %5.1f\n", j*delt, temp[90]);			//result.txtファイルに出力
        }
	}				// 時間ステップ繰り返し終了

///////////////////////////////////////////////////////////


	fclose(fp);		// 開いたresult.txtを閉じる。
}				// main( void )の終わり（プログラムの終わり）