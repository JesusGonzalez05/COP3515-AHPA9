#include <stdio.h>
#include <stdlib.h>

// Initial tank capacities
#define NUM_TANKS 4
int maxCapacities[NUM_TANKS] = {100, 75, 50, 150};
int tanks[NUM_TANKS] = {100, 75, 50, 150};

// Function prototypes
int carArrived();
void refillRequest(int pumpNumber);
void printTanks();

int main() {
    int pump;
    unsigned int seed;
    int numCars;

    // Read seed and number of cars from input (to match test cases)
    if (scanf("%u %d", &seed, &numCars) != 2) {
        printf("Error: expected seed and number of cars as input.\n");
        return 1;
    }

    srand(seed); // set random seed

    for (int i = 0; i < numCars; i++) {
        pump = carArrived(); // get which pump is used
        printf("Car arrived at pump %d.\n", pump + 1);

        // Serve car: reduce 10 gallons from the selected tank
        tanks[pump] -= 10;

        // Check if tank needs refill
        if (tanks[pump] < 20) {
            refillRequest(pump);
        }

        // Print current tank status
        printTanks();
        printf("\n");
    }

    return 0;
}

// Simulate a car arriving at a random pump
int carArrived() {
    return rand() % NUM_TANKS; // returns pump number 0–3
}

// Simulate requesting a refill truck
void refillRequest(int pumpNumber) {
    printf("Pump %d tank low! Requesting refill...\n", pumpNumber + 1);
    tanks[pumpNumber] = maxCapacities[pumpNumber]; // refill to full capacity
    printf("Pump %d tank refilled to %d gallons.\n", pumpNumber + 1, tanks[pumpNumber]);
}

// Print the status of all tanks
void printTanks() {
    printf("Current tank levels: ");
    for (int i = 0; i < NUM_TANKS; i++) {
        printf("[Pump %d: %d] ", i + 1, tanks[i]);
    }
    printf("\n");
}
