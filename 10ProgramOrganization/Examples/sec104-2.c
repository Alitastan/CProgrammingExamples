/*
*   For each of the following scopes, list all variable and
*   parameter names visible in that scope. If there's more 
*   than one variable or parameter with the same name, indicate
*   which one is visible.
*/

int b, c;

/*  local variable b, d and external variable c is visible. */
void f (void)
{
    int b, d;
}

/*  local variable c, a and d is visible.   */
void g (int a)
{
    int c;
    {
        int a, d;
    }
}

/*  local variable c and d, external variable b is visible. */
int main (void)
{
    int c, d;
}