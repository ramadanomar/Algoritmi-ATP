#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

const int M = 45;  // Caini
const int N = 30;  // Pisici
const int POPULATION_SIZE = 100;
const int MAX_ITER = 10000;

std::random_device rd;
std::mt19937 gen(rd());

// Returns a new chromosome
std::vector<int> create_chromosome() {
    std::vector<int> chromosome(M + N);
    std::fill(chromosome.begin(), chromosome.begin() + M, 0);  // Caini
    std::fill(chromosome.begin() + M, chromosome.end(), 1);  // Pisici
    std::shuffle(chromosome.begin(), chromosome.end(), gen);
    return chromosome;
}

// Returns fitness of a chromosome
int calculate_fitness(const std::vector<int>& chromosome) {
    int fitness = 0;
    int n = chromosome.size();
    for (int i = 0; i < n; ++i) {
        if (chromosome[i] == 0 && chromosome[(i+1)%n] == 1 && chromosome[(i+2)%n] == 0)
            ++fitness;
    }
    return fitness;
}

// Tournament selection
std::vector<int> select_parent(const std::vector<std::vector<int>>& population) {
    std::uniform_int_distribution<> dis(0, POPULATION_SIZE - 1);
    int i = dis(gen);
    int j = dis(gen);
    if (calculate_fitness(population[i]) < calculate_fitness(population[j]))
        return population[i];
    else
        return population[j];
}

// Single point crossover
std::vector<int> crossover(const std::vector<int>& parent1, const std::vector<int>& parent2) {
    std::uniform_int_distribution<> dis(0, M + N - 1);
    int crossover_point = dis(gen);
    std::vector<int> offspring(M + N);
    std::copy(parent1.begin(), parent1.begin() + crossover_point, offspring.begin());
    std::copy(parent2.begin() + crossover_point, parent2.end(), offspring.begin() + crossover_point);
    return offspring;
}

// Mutation
void mutate(std::vector<int>& chromosome) {
    std::uniform_int_distribution<> dis(0, M + N - 1);
    int mutation_point = dis(gen);
    chromosome[mutation_point] = 1 - chromosome[mutation_point];
}

int main() {
    // Initialize
    std::vector<std::vector<int>> population(POPULATION_SIZE);
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        population[i] = create_chromosome();
    }

    for (int iter = 0; iter < MAX_ITER; ++iter) {
        // Calculate fitness of each chromosome and check solution
        for (const auto& chromosome : population) {
            int fitness = calculate_fitness(chromosome);
            if (fitness == 0) {
                for (int gene : chromosome) {
                    std::cout << gene;
                }
                std::cout << '\n';
                return 0;
            }
        }

        std::vector<std::vector<int>> new_population;
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            std::vector<int> parent1 = select_parent(population);
            std::vector<int> parent2 = select_parent(population);
            std::vector<int> offspring = crossover(parent1, parent2);
            mutate(offspring);
            new_population.push_back(offspring);
        }

        population = new_population;
    }

    std::cout << "Nu am gasit nicio solutie\n";
    return 0;
}
