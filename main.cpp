
#include "mbed.h"
#include "LSM6DSLSensor.h"
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

    Angle tilt = atan(int y / sqrt (pow(int x, int x) + pow(int z, int z)));
    float result = 0;

    return result;

    

double rad2deg(double rad){
    /*Convert radians to degrees*/
    double deg = 0;
    deg = rad * (180.0/pi);
    return deg;
}
    

 

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