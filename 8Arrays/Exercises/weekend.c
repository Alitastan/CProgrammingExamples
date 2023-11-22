
#include <stdbool.h>

int main (void)
{
    bool weekend[7] = {true, false, false, false, false, false, true};
    bool designatedWeekend[7] = {[0] = true, [6] = true}; /* C99. and above? */
}
