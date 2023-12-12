

int main (void)
{
    int i, *p = &i, *q = &i;

    /**
     * Legal assignments
    */

   p = q;
   *p = *q;
   p = *&q;
}