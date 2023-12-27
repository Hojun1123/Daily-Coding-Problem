#include <stdio.h>
long long func(long long r)
{
        long long i;
        long long cnt;
        long long pow, pow1, pow2;
        for(i=1; ; i++){
                pow = i*i;
                pow1 = pow - i + 1;
                pow2 = pow + i;
                if(pow1 <= r && pow2 >= r){
                        if(r <= pow)
                                cnt = i*2 -1;
                        else
                                cnt = i*2;
                        return cnt;
                }
        }
}

void print(const long long *arr, long long t)
{
        long long i;
        for(i=0; i<t; i++)
                printf("%lld\n", arr[i]);
}

int main()
{
        long long T;
        long long x,y;
        long long i;
        scanf("%lld", &T);
        long long result[T];
        for(i=0; i<T; i++){
                scanf("%lld %lld", &x, &y);
                result[i] = func(y-x);
        }

        print(result, T);

        return 0;

}