/*
 * #define LANG C
 */

#include <stdio.h> /** standard io **/
#include <stdlib.h> /** exit(), atof and the lot **/
#include <unistd.h> /** needed for getopt() **/

/*** SYMBOIC CONSTANTS ***/
#define VERSION "1.0" /** version string array **/
#define HELP help(argv[0]) /** will insert this instead of help(argv[0]) every time **/
#define FLOATARG atof(optarg) /** atof is kind of vague, so a #define is better **/
#define TOVERH "FAHR\tCELSIUS\tKELVIN\n" /** just so I don't have to type it out ever time **/
#define OPTS "vk:f:c:h" /** I prefer a #define to this -> b:ull:s::hi:t: **/
/** For reference, an option followed by a double colon **/
/**        signifies that it takes no arguments         **/
/**  while an option followed by one colon signifies    **/
/**           that it takes one argument.               **/

char *ver = VERSION;

void help(char *s);

/*** Fahrenheit ***/
float FK(float F) {
    return(((5.0 / 9.0) * (F - 32.0)) + 273.15);
}
float FC(float F) {
    return((5.0 / 9.0) * (F - 32.0));
}

void printfahr(float F) {
    printf(TOVERH);
    printf("%4.3f\t%5.3f\t%5.3f\n", F, FC(F), FK(F));
}

/** Celsius **/
float CK(float C) {
    return((C + 273.15));
}
float CF(float C) {
    return((C * (9.0 / 5.0) - 32.0));
}
void printc(float C) {
    printf(TOVERH);
    printf("%4.3f\t%5.3f\t%5.3f\n", CF(C), C, CK(C));
}

/*** Kelvin ***/
float KC(float K) {
    return(K - 273.15);
}
float KF(float K) {
    return((K - 273.15) * (9.0 / 5.0) - 32.0);
}
void printk(float K) {
    printf(TOVERH);
    printf("%4.3f\t%5.3f\t%5.3f\n", KF(K), KC(K), K);
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        HELP;
        exit(argc);
    }
    else {
        char arg = '\0';
        while((arg = getopt(argc, argv, OPTS)) != -1)
        {
            switch(arg) {
                case 'c':
                    if(optarg == NULL)
                    {
                        HELP;
                        exit(1);
                    }
                    else {
                        printc(FLOATARG);
                    }
                break;
    
                case 'f':
                    if(optarg == NULL)
                    {
                        HELP;
                        exit(1);
                    }
                    else {
                        printfahr(FLOATARG);
                    }
                break;
    
                case 'h':
                    HELP;
                break;
    
                case 'k':
                    if(optarg == NULL)
                    {
                        HELP;
                        exit(1);
                    }
                    else {
                        printk(FLOATARG);
                    }
                break;
    
                case 'v':
                    printf("%s\n", ver);
                break;

                default:
                    HELP;
                break;
            }
        }
    }
    return 0;
}

void help(char *s) {
    printf("USAGE:\t%s [-c] Celsius [-f] Fahrenheit [-h] [-k] Kelvin [-v]\n", s);
}

