#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
#define Alert_Threshold 200

float farenheitToCelcius(float farenheit);

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > Alert_Threshold) {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    } else {
        return 200;
    }
}

float farenheitToCelcius(float farenheit) {
    return ((farenheit-32)*5/9);
}
    
void alertInCelcius(float farenheit) {
    float celcius = farenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount!=0);
    alertInCelcius(303.6);
    assert(alertFailureCount!=0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
