#include <stdio.h>
#include <time.h>

int main()

{

    time_t orig_format;
    time(&orig_format);

    printf ("Universal Time is %s",
    asctime(gmtime(&orig_format)));

    return 0;

}
