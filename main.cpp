
#include "mbed.h"
#include "LSM6DSLSensor.h"
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


    }
}
/* Example of the readings from Coolterm

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

