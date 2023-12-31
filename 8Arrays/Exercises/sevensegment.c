/* Suppose that we want to set up an array that remembers which 
*  segments should be "on" for each digit. 
*/

int main (void)
{
    // 0 to 9 
    const int segments[10][7] = {   {1, 1, 1, 1, 1, 1, 0}, 
                                    {0, 1, 1, 0, 0, 0, 0},
                                    {1, 1, 0, 1, 1, 0, 1},
                                    {1, 1, 1, 1, 0, 0, 1},
                                    {0, 1, 1, 0, 0, 1, 1},
                                    {1, 0, 1, 1, 0, 1, 1},
                                    {1, 0, 1, 1, 1, 1, 1},
                                    {1, 1, 1, 0, 0, 0, 0},
                                    {1, 1, 1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 1, 1}   }; 

    // short cut
    const int segments1[10][7] = {   {1, 1, 1, 1, 1, 1}, 
                                    {0, 1, 1},
                                    {1, 1, 0, 1, 1, 0, 1},
                                    {1, 1, 1, 1, 0, 0, 1},
                                    {0, 1, 1, 0, 0, 1, 1},
                                    {1, 0, 1, 1, 0, 1, 1},
                                    {1, 0, 1, 1, 1, 1, 1},
                                    {1, 1, 1},
                                    {1, 1, 1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 1, 1}   }; 
}