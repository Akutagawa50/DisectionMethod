#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double x_cosx(double x){// f(x)=x+cos(x) の関数
    return x + cos(x);
}

int main(){
    double rng_max = 10000.0;   //最初に探す範囲の最大値（値は適当）
    double rng_min = -rng_max;  //最初に探す範囲の最小値（値は適当）
    double h = rng_max/10.0;    //範囲を探すときの分割数
    double error = 0.000000001; //収束判定のときの誤差
    double xmin=0, xmax=0;      //それぞれxの最小値，最大値を保存する変数
    double x;                   //xminとxmaxの平均を保存する

    for(int i=0; i<50; i++){    //50回動かす
        for(double n=rng_min; n<rng_max; n+=h){//分割した範囲を1つずつ見ていく
            double y1 = x_cosx(n);      //それぞれのyの値を計算
            double y2 = x_cosx(n+h);    
            if(y1<0.0 && y2>0.0){       //y1とy2の間に0があったらbreak
                xmin = n;
                xmax = n+h;
                break;
            }
            else if (y1>0.0 && y2<0.0){ //同様に0が間にあったらbreak
                xmax = n;
                xmin = n+h;
                break;
            }
        }
        x = (xmin+xmax)/2;                      //xminとxmaxの平均を計算
        if(rng_max-x<error && x-rng_min<error){ //収束判定
            cout << i+1 << "回目で収束しました" << endl;
            break;
        }
        
        rng_min = xmin; //探索範囲の最小値を更新
        rng_max = xmax; //探索範囲の最大値を更新
        h /= 10.0;      //分割する幅を更新
    }
    //結果を出力
    cout <<"x= "<< fixed << setprecision(6) << x << endl;
    cout << "f(x) =" << fixed << setprecision(6) << x_cosx(x) << endl;

    return 0;
}