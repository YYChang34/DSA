#include <iostream>
using namespace std;

int main(void) {
	int x, y;
	cout << "請輸入x和y並以空格隔開" << endl;
	cin >> x >> y;

	char** c = (char**)malloc(x * sizeof(char*));

	int i, j;
	for(i = 0; i < x; i++) {
		c[i] = (char*)malloc((y + 1) * sizeof(char));
	}

	for(i = 0; i < x; i++) {
		cin >> c[i];
	}

	for(i = 0; i < x; i++) {
		for(j = 0; j < x - i - 1; j++) {
			if(**(c + j) < **(c + j + 1)) {
				char* temp = *(c + j);
				*(c + j) = *(c + j + 1);
				*(c + j + 1) = temp;
			}
		}
	}

	for(i = 0; i < x; i++) {
		cout << c[i] << endl;
	}

	for(i = 0; i < x; i++) {
		free(c[i]);
	}
	free(c);

	return 0;
}