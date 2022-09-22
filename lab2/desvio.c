#include <stdio.h>
#include <math.h>

int main(){
        long long sum = 0;
        int arr[10];
        for(int i = 0; i < 10; i++){
                int n; 
                scanf("%d", &n);
                sum += n;
                arr[i] = n;
        }
        
        const long double avg  = (long double)sum / 10;
        long double ans = 0;
        for(int i = 0; i < 10; i++){
                ans = arr[i] - avg;
                ans *= ans;
        } 
        printf("%Lf\n", sqrtl(ans));
        return 0;
}