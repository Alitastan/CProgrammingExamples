
#define N   5

int main (void)
{
    int a[N], *p;
    p = a;

    p == a[0]; // illegal
    p == &a[0]; // legal
    *p == a[0]; // legal
    p[0] == a[0]; // legal
}