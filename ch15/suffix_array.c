#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pstrcmp(char **str1, char **str2)
{
    return strcmp(*str1, *str2);
}

int comlen(char *str1, char *str2)
{
    int same_len = 0;
    while(*str1 && *str1 == *str2){
        str1 ++;
        str2 ++;
        same_len ++;
    }
    return same_len;
}

void find_repeted_str(char *str)
{
    int len = strlen(str);
    char **a = (char **)malloc(len * sizeof(char *));
    int i;

    for(i = 0; i < len; i ++){
        a[i] = &str[i];
        //printf("a[%d] : %s\n", i, a[i]);
    }

    qsort(a, len, sizeof(char *), pstrcmp);

    //for(i = 0; i < len; i ++){
    //    printf("a[%d] : %s\n", i, a[i]);
    //}
    
    int maxlen = 0;
    int maxi;
    for(i = 0; i < len - 1; i ++){
        int tmp = comlen(a[i], a[i + 1]);
        if(tmp > maxlen){
            maxlen = tmp;
            maxi = i;
        }
    }
    printf("%.*s\n", maxlen, a[maxi]);
}

int main()
{
    char str[100];
    while(scanf("%s", str) != EOF){
        find_repeted_str(str);
    }

	return 0;
}
