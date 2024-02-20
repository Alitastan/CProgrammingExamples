
#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 1

#if defined (DEBUG)
    #define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
#else
    #define PRINT_DEBUG(n)
#endif

#endif // DEBUG_H
