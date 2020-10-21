#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double x_cosx(double x){
    return x + cos(x);
}

int main(){
    double rng_min = -1000.0;
    double rng_max = 1000.0;
    double h = 100.0;
    double error = 0.0000001;
    double xmin=0, xmax=0;

    for(int i=0; i<10; i++){
        for(double n=rng_min; n<rng_max; n+=h){
            double y1 = x_cosx(n);
            double y2 = x_cosx(n+h);
            if(y1<0.0 && y2>0.0){
                xmin = n;
                xmax = n+h;
                break;
            }
            else if (y1>0.0 && y2<0.0){
                xmax = n;
                xmin = n+h;
                break;
            }
        }
        rng_min = xmin;
        rng_max = xmax;
        h /= 10.0;
    }
    double x = (xmax+xmin)/2.0;
    cout <<"x="<< fixed << setprecision(6) << x << endl;
    cout << "f(x)=" << fixed << setprecision(6) << x_cosx(x) << endl;

    return 0;
}