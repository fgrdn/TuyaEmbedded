//
//  tyMatrix.h
//  AutoCoding
//
//  Created by 傅浪 on 2018/6/11.
//

#ifndef tyMatrix_h
#define tyMatrix_h

#include <stdio.h>
#include <math.h>

typedef struct tyMatrix4 {
    float m[4][4];
} tyMatrix4;

void tyMatrixLoadIdentity(tyMatrix4 * result);

void tyMatrixScale(tyMatrix4 * result, float sx, float sy, float sz);

void tyMatrixTranslate(tyMatrix4 * result, float tx, float ty, float tz);

void tyMatrixRotate(tyMatrix4 *result, float angle, float x, float y, float z);

void tyMatrixMultiply(tyMatrix4 *result, tyMatrix4 *srcA, tyMatrix4 *srcB);

#endif /* tyMatrix_h */
