#include <cstdio>
#include <cstring>
#include <malloc.h>

#define MAX_SIZE 100

int main(void) {
     int x;
     scanf("%d\n", &x);
     char** c = (char**)malloc(x * sizeof(char*));

     int i, j, max_len_of_name = -1;
     for(i = 0; i < x; i++) {
          char temp[MAX_SIZE] = {};
          fgets(temp, MAX_SIZE-1, stdin);
          c[i] = (char*) malloc((strlen(temp)+1) * sizeof(char));
          strcpy(c[i], temp);
     }

     int len_of_first_word[x] = {0};
     int max_len_of_first_word = -1;
     for(i = 0; i < x; i++) {
          for (j = 0; ; j++) {
               if (c[i][j] == ' ') {
                    len_of_first_word[i] = j;
                    if (len_of_first_word[i] > max_len_of_first_word) {
                         max_len_of_first_word = len_of_first_word[i];
                    }
                    break;      
               }
          }
     }

     for(i = 0; i < x; i++) {
          int num_of_space = max_len_of_first_word - len_of_first_word[i];
          for (j = 0; j < num_of_space; j++) {
               printf(" ");
          }
          printf("%s", c[i]);
     }

     for(i = 0; i < x; i++) {
          free(c[i]);
     }

     free(c);
     return 0;
}