#include <stdio.h>

int tong(int a, int b)
{
    // printf("Tong!\n");
    return a + b;
}
int hieu(int a, int b)
{
    // printf("Hieu!\n");
    return a - b;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 7};
    char arr_char[] = {'a', 'b', 'c', 'd', 'e'};
    double arr_double[] = {3.141, 3.142, 3.143, 3.144, 3.145};

    void (*funcArr[])(int a, int b) = {&tong, &hieu};
    // Khai báo mảng địa chỉ arr

    void *arr_ptr[5] = {arr, arr_char, arr_double, funcArr};

    printf("Lay kieu du lieu cua int\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", *((int *)arr_ptr[0] + i));
    }

    printf("Lay kieu du lieu cua char\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", *((char *)arr_ptr[1] + i));
    }

    printf("Lay kieu du lieu cua double\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", *((double *)arr_ptr[2] + i));
    }

    return 0;
}
