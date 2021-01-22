#include <iostream>
using  namespace std;

#define E 0.0000000000001

double bringRadical(double x, double a) {
    return x*x*x*x*x + x + a;
}

double bisectionMethod(double a, double left, double right) {
    double middle = left + (right - left) / 2;//-10+10
    while (abs(right - left)> E) {
        if (bringRadical(left, a) == 0) {
            cout<<"Left border\n";
            return left;
        }
        if (bringRadical(right, a) == 0) {
            cout<<"Right border\n";
            return right;
        }
        if (bringRadical(middle, a) * bringRadical(left, a) >
        0) {
            left = middle;
        }
        else right = middle;
        middle = left + (right - left) / 2;
        cout<<"Middle: "<<middle<<" Left:"<<left<<" Right: "<<right<<endl;
    }
    return middle;


}

double chordMethod(double a, double left, double right){
    double tmp = 0, temp = 1;
    while(abs(tmp - temp) > E){
        if (bringRadical(left, a) == 0) {
            cout<<"Left border\n";
            return left;
        }
        if (bringRadical(right, a) == 0) {
            cout<<"Right border\n";
            return right;
        }
        temp = tmp;
        tmp = left - bringRadical(left, a) / (bringRadical(right, a) - bringRadical(left, a)) * (right - left);
        if((bringRadical(right, a) * bringRadical(tmp, a)) < 0) left = tmp;
        else right = tmp;
        cout<<"Left: "<<left<<" Right: "<<right<<endl;
    }
    return tmp;
}

int main() {
    double res1, res2;
    cout.precision(12);
    double a, left, right;
    cout<<"Enter a, left and right border\n";
    cin>>a>>left>>right;
    if (bringRadical(left, a) * bringRadical(right, a) > 0) {
        cout<<"Incorrect left and right border\n";
        return 0;
    }
    cout<<"BisectionMethod\n";
    res1 = bisectionMethod(a, left, right);
    cout<<"ChordMethod\n";
    res2 = chordMethod(a, left, right);
    cout<<"Result of bisection method: "<<res1<<". Result of chord method: "<<res2<<endl;
    cout<<"|res1 - res2| = "<<abs(res1 - res2);
    return 0;
}
