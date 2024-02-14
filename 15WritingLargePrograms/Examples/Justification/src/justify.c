/**
 * Heart of the program
 * 
 * for (;;)
 * {
 *      read word;
 *      if (can't read word)
 *      {
 *          write contents of line buffer without justification;
 *          terminate program;
 *      }
 *      if (word doesn't fit in line buffer)
 *      {
 *          write contents of line buffer with justification;
 *          clear line buffer;
 *       }
 *       add word to line buffer;
 * }
*/