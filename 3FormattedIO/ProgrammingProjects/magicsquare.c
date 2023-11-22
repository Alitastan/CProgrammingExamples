#include <stdio.h>

int main(void)
{
    int i1,i2,i3,i4,j1,j2,j3,j4,k1,k2,k3,k4,l1,l2,l3,l4;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &i1, &i2, &i3, &i4,
        &j1, &j2, &j3, &j4,
        &k1, &k2, &k3, &k4,
        &l1, &l2, &l3, &l4);

    printf("4x4 Matrix\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d",
    i1, i2, i3, i4,
    j1, j2, j3, j4,
    k1, k2, k3, k4,
    l1, l2, l3, l4);

    int rowSums, columnSums, diagonalSums;

    rowSums = i1 + i2 + i3 + i4;
    columnSums = i1 + j1 + k1 + l1;
    diagonalSums = i1 + j2 + k3 + l4;

    printf("\nRow Sums: %d\nColumn Sums: %d\nDiagonal Sums:%d\n",
    rowSums, columnSums, diagonalSums);

    return 0;

}