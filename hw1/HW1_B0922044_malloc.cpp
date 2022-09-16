#include <cstdio>
#include <malloc.h>

int main(void) {
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	char** c = (char**)malloc(x * sizeof(char*));

	int i, j;
	for(i = 0; i < x; i++) {
		c[i] = (char*)malloc((y + 1) * sizeof(char));
	}

	for(i = 0; i < x; i++) {
		scanf("%s", c[i]);
	}

	for(i = x - 2; i >= 0; i--) {
		for(j = 0; j <= i; j++) {
			if(**(c + j) < **(c + j + 1)) {
				char *temp = *(c + j + 1);
				*(c + j + 1) = *(c + j);
				*(c + j) = temp;
			}
		}
	}

	for(i = 0; i < x; i++) {
		printf("%s\n", c[i]);
	}

	for(i = 0; i < x; i++) {
		free (c[i]);
	}

	free (c);
	return 0;
}
