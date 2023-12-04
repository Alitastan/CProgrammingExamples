/*  
*   For each of the following scopes, list all variable and parameter
*   names visible in that scope 
*/

int a;

/*  a, b and c visible */
void f(int b)
{
    int c;
}

/*  a, d and e are visible  */
void g(void)
{
    int d;
    {
        int e;
    }
}

/*  a and f are visible. */
int main (void)
{
    int f;
}