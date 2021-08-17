/*
    Problem : โปรแกรมรับ input เป็นตัวเลขจํานวนเต็ม 1 ตัว แล้วแสดงผลการแยกตัวประกอบของตัวเลขนั้น
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <stdio.h>

int main() {

    int number;
    printf("Enter number : ");
    scanf("%d", &number);

    printf("Factoring result : ");
    int divider = 2;
    while(divider <= number / 2) {

        if(number % divider == 0) {
            number /= divider;
            printf("%d x ", divider);
        }
        else {

            divider++;
        }
    }
    printf("%d\n", number);

    return 0;
}