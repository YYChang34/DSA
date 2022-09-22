#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int x;
	cin >> x;

	char** str = (char**)malloc(x * sizeof(char*));

	int i, j, max = -1, len[x];
	for(i = 0; i < x; i++) {
		char Firstname[100] = {}, Lastname_1[100] = {}, Lastname_2[100] = {}, c;
		cin >> Firstname;
		cin >> Lastname_1;
		if((c = cin.get()) == ' ') {
			cin >> Lastname_2;
		}

		len[i] = strlen(Firstname);
		if(len[i] > max) {
			max = len[i];
		}

		str[i] = (char*)malloc((strlen(Firstname) + strlen(Lastname_1) + strlen(Lastname_2) + 1) * sizeof(char));
		strcpy(str[i], Firstname);
		strcat(str[i], " ");
		strcat(str[i], Lastname_1);
		if(strlen(Lastname_2) != 0) {
			strcat(str[i], " ");
			strcat(str[i], Lastname_2);
		}
	}

	for(i = 0; i < x; i++) {
		for(j = 0; j < max - len[i]; j++){
			cout << " ";
		}
		cout << str[i] << endl;
		free(str[i]);
	}

	free(str);

	return 0;
}