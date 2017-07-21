/*
 * Temperature converter.
 * http://www.cprogramming.com/challenges/celsius_converter_table.html
 *
 *  @author: Kyler Smith, 2017
 */
///////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdio.h>

///////////////////////////////////////////////////////////////////////
// GLOBALS
const float HIGH = 726.85;
const float LOW = -273.15;
const float HIGH_STEP = 100;
const float LOW_STEP = 0;

///////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
void getInput(float *x, float *y, float *z);
float convertCToF(float temp);

/**
 * Entry point for the program.
 */
int main(int argc, const char * argv[]) {
    
    float beginnningTempC = 0.0, endingTempC = 0.0, step = 0.0;
    getInput(&beginnningTempC, &endingTempC, &step);

    // Error checking
    while(beginnningTempC < LOW || endingTempC > HIGH || step < LOW_STEP || step > HIGH_STEP) {
        printf("Something was incorrect. Try again.\n");
        getInput(&beginnningTempC, &endingTempC, &step);
    }
    
    // Formatting
    printf("Celsius\t\tFehrenheit\n");
    printf("-------\t\t----------\n");
    
    // Printing
    while(beginnningTempC < endingTempC) {
        printf("%f\t%f\n", beginnningTempC, convertCToF(beginnningTempC));
        beginnningTempC += step;
    }
    return 0;
}

/**
 * Gets the input from the user.
 *
 * @param x where to put the beginning temp
 * @param y where to put the ending temp
 * @param z where to put the step
 */
void getInput(float *x, float *y, float *z) {
    printf("Enter a temperatur(celsius) >= -273.15: ");
    scanf("%f", x);
    printf("Enter a temperatur(celsius) <= 726.85: ");
    scanf("%f", y);
    printf("Enter a step, 0 < step < 100: ");
    scanf("%f", z);
}

/**
 * Returns the value passed converted to fehrenheit.
 *
 * @param temp Temperature to be converted to celsius
 * @return float
 */
float convertCToF(float temp) {
    return (temp * (1.8) + 32);
}
