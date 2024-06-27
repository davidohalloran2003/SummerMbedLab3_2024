
#include "mbed.h"
#include "LSM6DSLSensor.h"
<<<<<<< HEAD
#include <cmath>

#define PI 3.141592654

static DevI2C devI2c(PB_11,PB_10);
static LSM6DSLSensor acc_gyro(&devI2c,0xD4,D4,D5); // high address



float computeAngle(int x, int y, int z){ 
    //computeAngle function to compute the tilt angles based on the accelerometer readings. 
    float roll, pitch;
    
    // Calculate roll angle (φ)
    roll = atan2(y, sqrt(x*x + z*z)) * 180.0 / PI;

    // Calculate pitch angle (θ)
    pitch = atan2(-x, sqrt(y*y + z*z)) * 180.0 / PI;

    // Return results in degrees
    return roll;
}
//This returns a tilt sensing result using the accelerometer data 
//from the sensor on the STM32 board.

/* Simple main function */
int main() {
    uint8_t id;
    int32_t axes[3];
    float res=0;
    acc_gyro.init(NULL);

    acc_gyro.enable_x();
    acc_gyro.enable_g();

    printf("This is an running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    acc_gyro.read_id(&id);
    printf("LSM6DSL accelerometer & gyroscope = 0x%X\r\n", id);

    while(1) {

        acc_gyro.get_x_axes(axes);
        res = computeAngle(axes[0], axes[1], axes[2]);
        printf("LSM6DSL: %6d, %6d, %6d, %3.2f\r\n", axes[0], axes[1], axes[2], res);


        thread_sleep_for(2000);

=======
#include <utility>

#define PI 3.141592654

static DevI2C devI2c(PB_11,PB_10);
static LSM6DSLSensor acc_gyro(&devI2c,0xD4,D4,D5); // high address


float computeAngle(int x, int y, int z){
    float result = 0;

    return result;
}
/*
//from here is my coding added to work out the 'compute Angle'

*/

    float tan(int y / sqrt (pow(int x, int x) + pow(int z, int z)));
    float result = 0;

    return result;
    
>>>>>>> 4e17170da18ea1b10efafbbdb2d1ee20f4cb3f8a

 

int make_integer_sequence<class _Tp, _Tp _Np> () {

    double num = 1.0;
    double result;

    result = tan(num);

    printf("Inverse of tan(%.2f) = %.2f in radians", num, result);

    // Converting radians to degrees
    result = (result * 180) / PI;
    printf("\nInverse of tan(%.2f) = %.2f in degrees", num, result);

    return 0;
}
<<<<<<< HEAD
/* Example of the readings from Coolterm
=======
    
 /*
 
 //   atan(y / sqrt (pow(x,x) + pow(z,z)))

//  #include <iostream>
// #include <cmath>
// int main() {
//     double x = 0.5;
//     double arctangentValue = atan(x);
//     std::cout << "Arctangent of " << x << " is: " << sineValue << std::endl;
//    return 0;
// }
>>>>>>> 4e17170da18ea1b10efafbbdb2d1ee20f4cb3f8a

LSM6DSL:   -136,    -16,   1034, -0.88
LSM6DSL:   -135,    -15,   1033, -0.82
LSM6DSL:   -136,    -14,   1034, -0.77
LSM6DSL:   -860,    127,    556, 7.07
LSM6DSL:    821,    270,    534, 15.41
LSM6DSL:    236,    819,    553, 53.72
LSM6DSL:     92,   -802,    625, -51.77
LSM6DSL:    251,    101,    900, 6.17
LSM6DSL:    -19,     -1,   1045, -0.05
LSM6DSL:   -554,    -28,    889, -1.53
LSM6DSL:    530,    -34,    884, -1.89
LSM6DSL:    548,    -50,    879, -2.76
LSM6DSL:    552,    -49,    869, -2.72
LSM6DSL:    -39,    303,    992, 16.97
LSM6DSL:      2,   -687,    760, -42.11
LSM6DSL:     18,   -707,    772, -42.48
LSM6DSL:     14,    556,    878, 32.34
LSM6DSL:     24,    568,    830, 34.37
LSM6DSL:     60,    666,    760, 41.14
LSM6DSL:    -46,    912,     42, 86.09
LSM6DSL:    -43,    976,     76, 84.89
LSM6DSL:    -34,    972,      7, 87.95
LSM6DSL:    -64,     48,    963, 2.85
LSM6DSL:    -21,    -20,   1042, -1.10
LSM6DSL:    -20,    -19,   1041, -1.05
LSM6DSL:    -20,    -19,   1041, -1.05
*/

// Converting radians to degrees
    result = (result * 180) / PI;
    printf("\nInverse of tan(%.2f) = %.2f in degrees", num, result);


//end of my notes on compute value 
*\



/* Simple main function */
int main() {
    uint8_t id;
    int32_t axes[3];
    float res=0;
    acc_gyro.init(NULL);

    acc_gyro.enable_x();
    acc_gyro.enable_g();

    printf("This is an running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    acc_gyro.read_id(&id);
    printf("LSM6DSL accelerometer & gyroscope = 0x%X\r\n", id);

    while(1) {

        acc_gyro.get_x_axes(axes);
        res = computeAngle(axes[0], axes[1], axes[2]);
        printf("LSM6DSL: %6d, %6d, %6d, %3.2f\r\n", axes[0], axes[1], axes[2], res);


        thread_sleep_for(2000);

/* Example of some of the printed data from Coolterm from the above coding for the mbed accelerometer example

// This is an running on Mbed OS 6.15.1.
// LSM6DSL accelerometer & gyroscope = 0x6A
// LSM6DSL:     -7,     -5,   1038, 0.00
// LSM6DSL:     -6,     -4,   1038, 0.00
// LSM6DSL:   -242,   -111,   1027, 0.00
// LSM6DSL:   -247,    702,   -480, 0.00
// LSM6DSL:    109,    457,   -596, 0.00
// LSM6DSL:   -423,    356,   1424, 0.00
// LSM6DSL:    955,   -286,   -182, 0.00
// LSM6DSL:   -178,   -980,     25, 0.00
// LSM6DSL:   -998,     27,    235, 0.00
// LSM6DSL:    425,    941,   -572, 0.00
// LSM6DSL:    390,    125,   -872, 0.00
// LSM6DSL:     -9,     28,   1041, 0.00
// LSM6DSL:     -7,     -6,   1039, 0.00
// LSM6DSL:     -7,     -4,   1039, 0.00
// LSM6DSL:     -7,     -4,   1038, 0.00
// LSM6DSL:     -7,     -4,   1038, 0.00
// LSM6DSL:     -8,     -4,   1038, 0.00
// LSM6DSL:     -8,     -5,   1039, 0.00

*/
    }
}