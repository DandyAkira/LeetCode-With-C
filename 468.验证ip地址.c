/*
 * @lc app=leetcode.cn id=468 lang=c
 *
 * [468] 验证IP地址
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int containIPV4(char * queryIP, int lenth){
    for(int i=0; i<lenth; i++){
        if(queryIP[i] == '.') return i;
    }
    return -1;
}

int containIPV6(char * queryIP, int lenth){
    for(int i=0; i<lenth; i++){
        if(queryIP[i] == ':') return i;
    }
    return -1;
}

char * validIPAddress(char * queryIP){
    int len = strlen(queryIP);
    int c4 = containIPV4(queryIP, len);
    int c6 = containIPV6(queryIP, len);
    if(c4 != -1){
        if(c6 != -1){
            return "Neither\0";
        }
        char *p = strtok(queryIP, ".");
        int size = 0;
        while (p)
        {
            size++;
            if(p[0] == '0' && strlen(p) > 1) return "Neither\0";
            for(int i=0; i<strlen(p); i++){
                if(p[i] < '0' || p[i] > '9') return "Neither\0";
            }
            int x = atoi(p);
            if(x < 0 || x > 255) return "Neither\0";
            p = strtok(NULL, ".");
        }
        if(size != 4) return "Neither\0";
        return "IPv4\0";
    }

    if(c6 != -1){
        char *p = strtok(queryIP, ":");
        int size = 0;
        while (p)
        {
            size++;
            if(strlen(p)<1 || strlen(p)>4) return "Neither\0";
            for(int i=0; i<strlen(p); i++){
                if(isdigit(p[i]) || (p[i] >= 'a' && p[i] <= 'f') || (p[i] >= 'A' && p[i] <='F')) continue;
                else return "Neither\0";
            }
        }
        if(size != 8) return "Neither\0";
        
        return "IPv6\0";
    }

    return "Neither\0";
}
// @lc code=end

