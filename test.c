#include <stdio.h>
#define N 10
double fun(int a[], int n) {
    double s=0;
    for(int i=0;i<n;i++) s+=a[i];
    return s/n;
}
int main(){

}