#include <stdio.h>

#define PI 3.14159265358979323846

double getDiameterNormal(double radius) {
    return 2.0 * radius;
}

double getCircumferenceNormal(double radius) {
    return 2.0 * PI * radius;
}

double getAreaNormal(double radius) {
    return PI * radius * radius;
}

#define GET_DIAMETER_MACRO(r)      (2.0 * (r))
#define GET_CIRCUMFERENCE_MACRO(r) (2.0 * PI * (r))
#define GET_AREA_MACRO(r)          (PI * (r) * (r))

static inline double getDiameterInline(double radius) {
    return 2.0 * radius;
}

static inline double getCircumferenceInline(double radius) {
    return 2.0 * PI * radius;
}

static inline double getAreaInline(double radius) {
    return PI * radius * radius;
}

int main(void) {
    double radius;

    printf("Enter the radius of the circle: ");
    if (scanf("%lf", &radius) != 1 || radius < 0) {
        printf("Error: Invalid radius\n");
        return 1;
    }

    printf("\n1. NORMAL FUNCTIONS:\n");
    printf("Diameter      : %.4f\n", getDiameterNormal(radius));
    printf("Circumference : %.4f\n", getCircumferenceNormal(radius));
    printf("Area          : %.4f\n", getAreaNormal(radius));

    printf("\n2. MACRO FUNCTIONS:\n");
    printf("Diameter      : %.4f\n", GET_DIAMETER_MACRO(radius));
    printf("Circumference : %.4f\n", GET_CIRCUMFERENCE_MACRO(radius));
    printf("Area          : %.4f\n", GET_AREA_MACRO(radius));

    printf("\n3. INLINE FUNCTIONS:\n");
    printf("Diameter      : %.4f\n", getDiameterInline(radius));
    printf("Circumference : %.4f\n", getCircumferenceInline(radius));
    printf("Area          : %.4f\n", getAreaInline(radius));

    return 0;
}