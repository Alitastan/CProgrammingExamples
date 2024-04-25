
#include <stdio.h>

#define COUNTRY_NUMBER \
    ((int) (sizeof(country_codes) / sizeof(country_codes[0])))

#define COUNTRY_FOUND   1
#define COUNTRY_NOT_FOUND 2

struct dialing_code
{
    char *country;
    int code;
};

const struct dialing_code country_codes[] = 
{
    {"Argentina",            54}, {"Bangladesh",      880},
    {"Brazil",               55}, {"Burma (Myanmar)",  95},
    {"China",                86}, {"Colombia",         57},
    {"Congo, Dem. Rep. of", 243}, {"Egypt",            20},
    {"Ethiopia",            251}, {"France",           33},
    {"Germany",              49}, {"India",            91},
    {"Indonesia",            62}, {"Iran",             98},
    {"Italy",                39}, {"Japan",            81},
    {"Mexico",               52}, {"Nigeria",         234},
    {"Pakistan",             92}, {"Philippines",      63},
    {"Poland",               48}, {"Russia",            7},
    {"South Africa",         27}, {"South Korea",      82},
    {"Spain",                34}, {"Sudan",           249},
    {"Thailand",             66}, {"Turkiye",           90},
    {"Ukraine",             380}, {"United Kingdom",   44},
    {"United States",         1}, {"Vietnam",          84}
};



int main (void)
{
    int code;
    printf("Enter the country code: ");
    scanf(" %d", &code);

    int i;
    for (i = 0; i < COUNTRY_NUMBER; i++)
    {
        if (code == country_codes[i].code)
        {
            printf("The corresponding country is \"%s\"\n", country_codes[i].country);
            return COUNTRY_FOUND;
        }

    }

    printf("The country is not found!\n");
    return COUNTRY_NOT_FOUND;

}

