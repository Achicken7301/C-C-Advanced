#include "main.h"

int main(int argc, char const *argv[])
{
    Vector v1;
    v1.pushBack(&v1, 1);
    v1.pushBack(&v1, 2);
    v1.pushBack(&v1, 3);
    return 0;
}