#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

struct point {
    double x;
    double y;
} co[100];

int main() {
    double min = DBL_MAX; // 使用双精度浮点数的最大可能值作为初始值
    int a = 0, b = 1;

    for (int i = 0; i < 100; ++i) {
        co[i].x = (double)rand() / (double)RAND_MAX;
        co[i].y = (double)rand() / (double)RAND_MAX;

    }

    for (int i = 0; i < 100; ++i) {
        for (int j = i + 1; j < 100; ++j) {
            double distance = sqrt(pow(co[i].x - co[j].x, 2) + pow(co[i].y - co[j].y, 2));
            if (distance < min) {
                min = distance;
                a = i;
                b = j;
            }
        }
    }

    printf("E((%.2f,%.2f),(%.2f,%.2f)) = %.2f", co[a].x, co[a].y, co[b].x, co[b].y, min);
    return 0;
}
