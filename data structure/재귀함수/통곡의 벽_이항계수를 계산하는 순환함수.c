#include <stdio.h>

int C(int n, int k) {
	if (k == 0 || k == 1) {
		return 1;
	}
	return C(n - 1, k - 1) + C(n - 1, k);
}

int main(void) {
	
}