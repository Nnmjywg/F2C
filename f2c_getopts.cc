/*
 * #define LANG C++
 */
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define VERSION "1.0"
#define HELP help(argv[0])
#define FLOATARG atof(optarg)
#define OPTS "vhk:f:c:"
/** For reference, an option followed by a nothing      **/
/**        signifies that it takes no arguments         **/
/**  while an option followed by one colon signifies    **/
/**         that it takes a required argument           **/

std::string ver = VERSION;

void help(char *s);
namespace Fahrenheit
{
    float FK(float F) {
        return ((5.0/9.0) * (F - 32.0) + 273.15);
    }

    float FC(float F) {
        return ((5.0/9.0) * (F - 32.0));
    }
    
    void printfahr(float F) {
        std::cout << "FAHR\tCELSIUS\tKELVIN" << std::endl;
        printf("%4.3f\t%5.3f\t%5.3f\n", F, FC(F), FK(F));
    }      
}

namespace Celsius
{
    float CF(float C) {
        return ((C*(9/5)) + 32);
    }
    float CK(float C) {
        return (C+273.15);
    }
    void printc(float C) {
        std::cout << "FAHR\tCELSIUS\tKELVIN" << std::endl;
        printf("%4.3f\t%5.3f\t%5.3f\n", CF(C), C, CK(C));
    }
}

namespace Kelvin
{
    float KF(float K) {
        return (((9.0/5.0) * (K-273.15)) + 32);
    }    
    float KC(float K) {
        return (K-273.15);
    }    
    void printk(float K) {
        std::cout << "FAHR\tCELSIUS\tKELVIN" << std::endl;
        printf("%4.3f\t%5.3f\t%5.3f\n", KF(K), KC(K), K);
    }
}
int main(int argc, char *argv[])
{
    char arg = '\0';
    if(argc < 2 && argc == 1 && argc > 0) {
        help(argv[0]);
        exit(1);
    }
    /*** Use function getopt() defined in unistd.h to accept 5 arguments: -v, -h, -k, -f, and -c ***/
    while((arg=getopt(argc, argv, OPTS))!=-1)
    {                                                      
        switch(arg)
        {

            case 'v':
                std::cout << "The current version is: " << ver << std::endl;
            break;

            case 'h':
                HELP;
            break;
            
            case 'k':
                Kelvin::printk(FLOATARG);
            break;
            
            case 'f':
                Fahrenheit::printfahr(FLOATARG);
            break;

            case 'c':
                Celsius::printc(FLOATARG);
            break;

            default:
                HELP;
            break;
        }
    }
    return 0;
}

void help(char *s) {
    std::cout << "Usage:\t"<< s << " [-option] [argument]" << std::endl;
    std::cout << "option:\t" << "-c [temperature]: convert a Celsius temperature to Fahrenheit and Kelvin" <<  std::endl;
    std::cout << "\t" << "-f [temperature]: convert a Fahrenheit temperature to Celsius and Kelvin" << std::endl;
    std::cout << "\t" << "-h: show help information" << std::endl;
    std::cout << "\t" << "-k [temperature]: convert a Kelvin temperature to Fahrenheit and Celsius" << std::endl;
    std::cout << "\t" << "-v: show version information" << std::endl;
}
