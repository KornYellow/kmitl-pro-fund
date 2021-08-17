/*
    Problem : โปรแกรมรับ input เป็นตัวเลขจํานวนเต็ม 1 ตัว แล้วแสดงผลการแยกตัวประกอบของตัวเลขนั้น
    Author : กร โรจน์รัตนปัญญา (64010009)
*/

#include <stdio.h>

int gcd(int num_1, int num_2) {

    if (num_1 % num_2 == 0) return num_2;
    return gcd(num_2, num_1 % num_2);
}
int main() {

    int num_1, num_2;
    printf("Enter first number : ");
    scanf("%d", &num_1);
    printf("Enter second number : ");
    scanf("%d", &num_2);

    printf("Greatest common divisor : %d\n", gcd(num_1, num_2));
}