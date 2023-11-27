


#define COLUMN_SIZE 10


int sumArray (int a[], int n);

// Using Variable Length Array ( VLA )
int sumTwoDimensionalArray (int n, int m, int a[n][m]);

// Without Variable Length Array. First defining the column size
int sumTwoDimensionalArray2 (int a[][COLUMN_SIZE], int n);

int main (void)
{
    int total;
    int b[5] = {3, 0, 3, 4, 1}; 
    
    // So, normally to call this function we need to pass array b
    total = sumArray (b, 5);

    // If we don't need b anywhere else we can create b by using 
    // compound literal: an unnamed array that's created on the fly.
    total = sumArray ((int []) {3, 0, 3, 4, 1}, 5);

    return 0;
}


int sumArray (int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];
    
    return sum;
}


int sumTwoDimensionalArray (int n, int m, int a[n][m])
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            sum += a[i][j];

    return sum;
}

int sumTwoDimensionalArray2 (int a[][COLUMN_SIZE], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < COLUMN_SIZE; j++)
            sum += a[i][j];

    return sum;


}