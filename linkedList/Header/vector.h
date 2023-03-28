#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "main.h"

typedef struct
{
    int value;
    struct vector *next;

    void (*pushBack)(struct vector **, int);
} Vector;

void pushBack(Vector **vector, int value);

#endif