#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * longestPalindrome(char * str){
    if(strlen(str)<2){
        return str;
    }
    int s=0, e=0;
    int size = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        int cur_size=1;
        int x=i-1, y=i+1;
        while(x>=0 && y<strlen(str)){
            if(str[x] != str[y]) break;
            cur_size += 2;
            x--;
            y++;
        }
        if(cur_size > size){
            size = cur_size;
            s = x+1;
            e = y-1;
        }
    }

    for (int i = 0; i < strlen(str)-1; i++)
    {
        int cur_size=0;
        int x=i, y=i+1;
        while(x>=0 && y<strlen(str)){
            if(str[x] != str[y]) break;
            cur_size += 2;
            x--;
            y++;
        }
        if(cur_size > size){
            size = cur_size;
            s = x+1;
            e = y-1;
        }
    }
    //printf("%d\n", size);
    //printf("%d %d\n", s, e);
    char res[size];
    strncpy(res, str+s, size);
    char *p=res;
    return p;
}

int main(int argc, char const *argv[])
{
    /* code */
    char a[] = "babad";
    char *p= a;
    printf("%s\n", longestPalindrome(p));
    return 0;
}
