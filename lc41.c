#include<stdio.h>
#include<math.h>

int trap(int* height, int heightsize){
    int leftmax[heightsize];
    int rightmax[heightsize];
    int res = 0;
    
    int left = height[0];
    int right = height[heightsize-1];
    int label;
    for(int i=0; i<heightsize; i++){
        if(height[i] > left){
            left = height[i];
        }
        leftmax[i] = left;
    }

    for(int i=heightsize-1; i>=0; i--){
        if(height[i] > right){
            right = height[i];
        }
        rightmax[i] = right;
    }

    for(int i=0; i<heightsize; i++){
        label = leftmax[i] < rightmax[i] ? leftmax[i] : rightmax[i];
        res += (label > height[i] ? (label-height[i]) : 0);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
