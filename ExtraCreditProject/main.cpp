// main.cpp
#include <iostream>
#include "elevator.h"

int main() {
    // Create an elevator system with 10 floors and 1 elevator
    Elevator elevator(10, 1);

    // Request elevator from outside (floor 1 to floor 5)
    elevator.requestFloor(1, 5);
    elevator.requestFloor(2, 6);

    // Add requests from inside the elevator (e.g., from floor 3 to floor 7)
    elevator.enterElevator(3, 7);

    // Start the elevator system
    elevator.operate();

    // Output the total requests and average wait time
    std::cout << "Total Requests: " << elevator.getTotalRequests() << std::endl;
    std::cout << "Average Wait Time: " << elevator.calculateWaitTime() << " seconds." << std::endl;

    return 0;
}