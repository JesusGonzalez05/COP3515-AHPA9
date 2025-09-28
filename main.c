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
    unsigned int seed;
    int numCars;

    // Read seed and number of cars
    if (scanf("%u %d", &seed, &numCars) != 2) {
        return 1; // exit if inputs are missing
    }

    srand(seed); // seed RNG

    for (int i = 0; i < numCars; i++) {
        int pump = carArrived(); // get which pump is used
        printf("Car arrived at pump %d.\n", pump + 1);

        // Serve car: reduce 10 gallons from the selected tank
        tanks[pump] -= 10;

        // Check if tank needs refill
        if (tanks[pump] < 20) {
            refillRequest(pump);
        }

        // Print current tank status
        printTanks();
    }

    return 0;
}

// Pick a random pump 0–3
int carArrived() {
    return rand() % NUM_TANKS;
}

// Refill when below 20
void refillRequest(int pumpNumber) {
    printf("Pump %d tank low! Requesting refill...\n", pumpNumber + 1);
    tanks[pumpNumber] = maxCapacities[pumpNumber]; // refill to full
    printf("Pump %d tank refilled to %d gallons.\n", pumpNumber + 1, tanks[pumpNumber]);
}

// Print status of all tanks
void printTanks() {
    for (int i = 0; i < NUM_TANKS; i++) {
        printf("Pump %d: %d gallons\n", i + 1, tanks[i]);
    }
}
