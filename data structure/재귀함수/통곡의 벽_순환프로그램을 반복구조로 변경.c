/*int sum(int n)
{
    if (n == 1) return 1;
    else return(n + sum(n - 1));
}
위 순환 프로그램을 반복구조로 바꾸기
*/
#include <stdio.h>

int sum(int n)
{
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += i;
    }
    return tmp;
}

int main(void) {
    int a = sum(10);
    printf("%d", a);
}