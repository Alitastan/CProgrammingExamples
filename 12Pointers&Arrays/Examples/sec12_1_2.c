

int main (void)
{
    int *high, *middle, *low;


    // This statement is illegal since pointers cannot be added
    middle = (low + high) / 2;
    // Instead we can write like this since high - low is an integer
    // and can be added to low pointer
    middle = low + (high - low) / 2;
}