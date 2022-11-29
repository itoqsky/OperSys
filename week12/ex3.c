#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "/usr/include/linux/input.h" 


bool prsing[256] = {0};
int cnt = 1;

void is_prsd(struct input_event e){
    if(e.value == 1) {
        prsing[e.code] = true;
        cnt ++;
    }
    if(e.value == 0) {
        prsing[e.code] = false;
        cnt --;
    }
}

int main(){
    struct input_event event;
    FILE *in = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    FILE *out = fopen("ex3.txt", "w");
    if(in == NULL) {
    fclose(out);
    }
    int spec_key[] = {KEY_C, KEY_A, KEY_P, KEY_E, KEY_N, KEY_O};
    while(1) {
        fread(&event, sizeof(struct input_event), 1, in);
        if(event.type == EV_KEY){
            is_prsd(event);
            bool ok = false;
            for (int i = 0; i < 6; i ++) {
                if(event.code == spec_key[i]) {
                    ok = true;
                    break;
                }
            }
            if(!ok) {
                for (int i = 0; i < 6; i ++) {
                    prsing[spec_key[i]] = false;
                }   
            }
            if(prsing[KEY_C] && prsing[KEY_A] && prsing[KEY_P]) {
                fprintf(out, "Get some cappuccino!\n");
            }
            if(prsing[KEY_P] && prsing[KEY_E]) {
                fprintf(out, "I passed the Exam!\n");
            }
            if(prsing[KEY_N] && prsing[KEY_O]) {
                fprintf(out, "NO!\n");
            }
            fflush(out);
        }
    }
 return 0;
}