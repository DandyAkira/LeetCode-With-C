/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char *tmp, char *digits, int index, char **res, char* letters[], int *returnSize){
    int d = digits[index] - '0';
    for(int i=0; i<strlen(letters[d-2]); i++){
        tmp[index] = letters[d-2][i];
        //printf("%s\n", tmp);
        //system("PAUSE");
        if(index == strlen(digits)-1) {
            strcpy(res[*returnSize], tmp);
            (*returnSize)++;
        } else{
            dfs(tmp, digits, index+1, res, letters, returnSize);
        }
        
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    
    char *two = "abc";
    char *three = "def";
    char *four = "ghi";
    char *five = "jkl";
    char *six = "mno";
    char *seven = "pqrs";
    char *eight = "tuv";
    char *nine = "wxyz";

    char * letters[] = {two, three, four, five, six, seven, eight, nine};


    int len = strlen(digits);
    *returnSize = 0;
    int count = (int)pow(4, len);
    char **res = (char **)malloc(sizeof(char*)*count);

    if(len < 1){
        return res;
    }

    for(int i=0; i<count; i++){
        res[i] = (char *)malloc(sizeof(char)*(len+1));
        res[i][len] = '\0';
        //printf("Init: %s\n", res[i]);
    }

    char a[] = "hello";
    char *p = a;
    char *x = &a[0];
    char *tmp = (char *)malloc(sizeof(char) * (len+1));
    tmp[len] = '\0';
    dfs(tmp, digits, 0, res, letters, returnSize);

    return res;
}
// @lc code=end

