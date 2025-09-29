/*
 * AHPA #9: A Gas Station
 *
 * You have been asked to create a C program to manage the gas 
 * pumps at a gas station. The station has four pumps connected 
 * to four tanks with capacities: 100, 75, 50, and 150. Every 
 * time a car fills up it takes 10 gallons. You‚Äôll know that a 
 * car has arrived because the carArrived function will return 
 * with a pump number. After a car has filled up, print out the 
 * current contents of all four tanks.
 *
 * Write a program that can track each of the four tanks. 
 * Update the amount of gas remaining in a tank when a car 
 * fills up. When a tank gets to less than 20 gallons of gas 
 * remaining, make a call to request a refill truck visit the 
 * station (refillRequest). This will cause the tank to be 
 * refilled automatically.
 *
 * Student Name: Jesus Gonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Include time.h as requested

/* Provided carArrived function */
int carArrived(void) {
    int randomnumber;
    do {
        randomnumber = rand() % 10;
    } while (randomnumber > 3);
    return randomnumber + 1;
}

int main(void) {
    int N, S;
    scanf("%d %d", &N, &S);   // Read number of cars and seed

    srand(S);  // Seed the RNG using input

    const int caps[4] = {100, 75, 50, 150};
    int tanks[4]      = {100, 75, 50, 150};

    for (int i = 0; i < N; i++) {
        int pump = carArrived();  // Get pump number (1-4)
        int idx = pump - 1;

        // Subtract 10 gallons
        tanks[idx] -= 10;

        // Print pump and tank status
        printf("Pump %d: -10 gal\n", pump);
        printf("Tanks: [%d, %d, %d, %d]\n", tanks[0], tanks[1], tanks[2], tanks[3]);

        // Refill if tank is below 20 gallons
        if (tanks[idx] < 20) {
            tanks[idx] = caps[idx];  // Refill to full
            printf("Refill: Tank %d refilled to %d\n", pump, caps[idx]);
            printf("Tanks: [%d, %d, %d, %d]\n", tanks[0], tanks[1], tanks[2], tanks[3]);
        }
    }

    return 0;
}
