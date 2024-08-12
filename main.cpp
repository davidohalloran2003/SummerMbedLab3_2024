#include "mbed.h"
#include "LSM6DSLSensor.h"

#define PI 3.141592654

// Initialise the I2C communication object and the LSM6DSLSensor object
static DevI2C devI2c(PB_11, PB_10);
static LSM6DSLSensor acc_gyro(&devI2c, 0xD4, D4, D5); // high address

// Initialise PWM outputs for the LEDs
PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);

// Constants for accelerometer range (adjust based on your sensor's range settings)
const float MIN_ACCEL = -2000.0f;  // Minimum value in milli-g
const float MAX_ACCEL = 2000.0f;   // Maximum value in milli-g

// Function to map accelerometer value to PWM duty cycle (0.0 to 1.0)
float map_accel_to_pwm(int accel) {
    return (accel - MIN_ACCEL) / (MAX_ACCEL - MIN_ACCEL);
}

/* Simple main function */
int main() {
    uint8_t id;
    int32_t axes[3];

    // Initialise the sensor
    acc_gyro.init(NULL);
    acc_gyro.enable_x();
    acc_gyro.enable_g();

    printf("This is an accelerometer example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    acc_gyro.read_id(&id);
    printf("LSM6DSL accelerometer & gyroscope = 0x%X\r\n", id);

    while (1) {
        // Get acceleration data
        acc_gyro.get_x_axes(axes);

        // Map acceleration to PWM duty cycle for LED brightness
        led1 = map_accel_to_pwm(axes[0]);  // Control brightness of LED1 using X axis
        led2 = map_accel_to_pwm(axes[1]);  // Control brightness of LED2 using Y axis
        led3 = map_accel_to_pwm(axes[2]);  // Control brightness of LED3 using Z axis

        // Print the acceleration data
        printf("LSM6DSL: X=%6d, Y=%6d, Z=%6d\r\n", axes[0], axes[1], axes[2]);

        // Wait for a short period before the next update
        thread_sleep_for(200);
    }
}