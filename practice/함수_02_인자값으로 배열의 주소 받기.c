#include <stdio.h>

int my_strlen(char* temp) {

	int count = 0;
	for (int i = 0; i < 1000; i++) {
		if (temp[i] == '\0') {
			return count;
		}
		count++;
	}

}

int main(void) {
	char temp[] = "hello World";
	printf("temp size : %d\n", my_strlen(temp));


	return 0;
}