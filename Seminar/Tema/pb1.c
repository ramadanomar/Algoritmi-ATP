#include <stdio.h>

typedef struct {
    int cost;
    int range;
    int tcas_radius;
} Plane;

int main() {
    Plane planes[] = {
        {100, 6000, 30},
        {60, 4200, 48},
        {50, 2800, 32}
    };
    int budget = 5000;

    int best_combination[3] = {0, 0, 0};
    double best_average_range = 0.0;

    for (int a = 0; a * planes[0].cost <= budget; a++) {
        for (int b = 0; a * planes[0].cost + b * planes[1].cost <= budget; b++) {
            int remaining_budget = budget - (a * planes[0].cost + b * planes[1].cost);
            int c = remaining_budget / planes[2].cost;

            int total_planes = a + b + c;
            double average_range = (a * planes[0].range + b * planes[1].range + c * planes[2].range) / (double)total_planes;
            double average_tcas_radius = (a * planes[0].tcas_radius + b * planes[1].tcas_radius + c * planes[2].tcas_radius) / (double)total_planes;

            if (average_tcas_radius >= 40.0 && average_range > best_average_range) {
                best_average_range = average_range;
                best_combination[0] = a;
                best_combination[1] = b;
                best_combination[2] = c;
            }
        }
    }

    printf("Cea mai buna combinatie: %d de tip A, %d de tip B, %d de tip C\n", best_combination[0], best_combination[1], best_combination[2]);
    printf("Autonomie medie: %.2lf\n", best_average_range);

    return 0;
}
