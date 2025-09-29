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
 * Student Name: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function Name: carArrived
 *
 * Description: Returns a random integer between 1-4.
 *
 * Input: None
 *
 * Output: Random integer between 1-4
 *
 */

int carArrived (void) {
  int randomnumber;

  /* Generate a random number between 0-10. Keep generating numbers
   * until you generate one that is between 0-3. */
  
  do {
    randomnumber = rand() % 10;  
  } while (randomnumber > 3);

  /* Add one to the generated random number to make it between 1-4 */
  return randomnumber+1;
}


int main(void) {
  /* Initialize the random number generator based on current time */
  srand(time(NULL));

  
}