/*int sum(int n)
{
    if (n == 1) return 1;
    else return(n + sum(n - 1));
}
�� ��ȯ ���α׷��� �ݺ������� �ٲٱ�
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