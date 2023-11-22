
#include <stdio.h>

int main(void)
{
    int gsiPrefix, groupIdentifier, publisherCode, itemNumber, checkDigit;

    printf("Enter ISBN: ");
    scanf("%d - %d - %d - %d - %d", &gsiPrefix, &groupIdentifier, &publisherCode, &itemNumber, &checkDigit);
    
    printf("GSI Prefix: %d\nGroup Identifier: %d\nPublisher Code: %d\nItem Number: %d\nCheck Digit: %d\n",
            gsiPrefix, groupIdentifier, publisherCode, itemNumber, checkDigit);

    return 0;

}