/**
 *  Convert a number between 0 and 15 into a character that
 *  represents the equivalent hex digit  
*/

// C allows pointers to be subscripted, so we can subscript string literals
char digit_to_hex_char (int digit)
{
    return "0123456789ABCDEF"[digit];
}