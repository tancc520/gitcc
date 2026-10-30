#include <stdio.h> //F=C*9/5+32,-200<C<200
int main() {
    double C,F;
    printf("?????????????:");
    scanf("%lf",&C);
    F=C*9/5+32;
    printf("%.1lf",F);
    return 0;
}