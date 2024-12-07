Heres the output that I got from the code

![output extra credit](https://github.com/user-attachments/assets/d0575b56-7018-4af6-a902-dc9d43863185)


output

![outttt](https://github.com/user-attachments/assets/a7b710af-cb8c-4a4d-8522-3853556db369)

min.cpp

![john](https://github.com/user-attachments/assets/ed1cbbb1-89ce-45ff-abb3-72ce2cc3b71b)

main.cpp: This is the entry point for the program where we will handle the simulation logic.
elevator.cpp: This will contain the implementation of the Elevator class and its methods.
elevator.h: The header file that declares the Elevator class.
Multiple Elevators: We initialize num_elevators elevators and store them in a vector.
Random Requests: We generate random requests for each elevator using the generateRandomRequests function.
Simulating Elevator Operations: The elevators operate in parallel, each processing its own requests. After operating, we print the total number of requests and the average wait time for each elevator.


Header.File Elavator.h

Attributes:

total_floors: The total number of floors the building has.
current_floor: The current floor of the elevator.
going_up: A boolean indicating whether the elevator is going up or down.
requests: A vector of all the requests made (both inside and outside the elevator).
pending_requests: A queue of requests that are yet to be processed.

Methods:

requestFloor: A method to request the elevator from outside (on any floor).
enterElevator: A method to request the elevator to move to a destination floor from inside the elevator.
operate: This method runs the elevator simulation, processing the requests.
getTotalRequests: Returns the total number of requests made.
calculateWaitTime: Calculates the average wait time of all requests.

Helper methods:

processRequests: Handles the logic for serving the requests based on priority.
moveElevator: Simulates the elevator moving between floors.
calculateTimeToServeRequest: Calculates the time to serve a particular request.

New Method - generateRandomRequests: This method will generate random requests for external and internal users.
Sorting Requests: The sortRequests method will prioritize requests based on proximity to the current floor of the elevator.
Modified Methods: The existing methods are modified to support the new logic for sorting requests and handling multiple elevators.

Elavator.cpp

requestFloor and enterElevator: These methods add requests to the requests vector and pending_requests queue.
operate: This simulates the elevator's operation, processing requests in the queue and moving the elevator.
processRequests: Handles the request, determines the time to serve it, and updates the elevator's status.
moveElevator: Simulates the movement of the elevator to the next floor based on the request.
calculateTimeToServeRequest: Calculates the time taken to serve a request based on the number of floors traveled.
calculateWaitTime: Calculates the average wait time for all users by summing the times and dividing by the number of requests.
generateRandomRequests: Generates 5 random requests for the elevator, where each request is a floor from which a user wants to go to another floor.
sortRequests: This method sorts the pending_requests by their proximity to the elevator's current floor to prioritize nearby requests.
Request Handling and Elevator Movement: Similar to the initial implementation, requests are processed one by one, and the elevator moves accordingly. The moveElevator method updates the elevator's floor after each request.
Time Calculation: The time to serve each request is calculated based on the number of floors traveled.



