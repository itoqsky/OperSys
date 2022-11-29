#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/linux/input.h"

int main()
{
    struct input_event event;
    FILE *in = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    FILE *out = fopen("ex2.txt", "w+");
    if (in == NULL)  {
        fclose(out);
    } 
    while (1) {
        fread(&event, sizeof(struct input_event), 1, in);
        if (event.type == EV_KEY) {
            if (event.value == 1) {
                fprintf(out, "PRESSED 00x%04x (%d)\n", event.code, event.code);
                printf("PRESSED 00x%04x (%d)\n", event.code, event.code);
            }
            else if (event.value == 0) {
                fprintf(out, "RELEASED 00x%04x (%d)\n", event.code, event.code);
                printf("RELEASED 00x%04x (%d)\n", event.code, event.code);
            }
        }
        fflush(out);
    }
    return 0;
}