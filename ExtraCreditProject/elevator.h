#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>

class Elevator {
public:
    Elevator(int total_floors, int elevator_id);

    void requestFloor(int from_floor, int to_floor);  // Request made from outside
    void enterElevator(int from_floor, int to_floor); // Request made from inside the elevator
    void operate();  // Simulate the elevator's movement and request handling

    int getTotalRequests() const;  // Get the total number of requests
    double calculateWaitTime() const;  // Calculate average wait time for all users

private:
    struct Request {
        int from_floor;
        int to_floor;
        bool is_inside; // true if inside request, false for outside request
    };

    int elevator_id;
    int total_floors;
    int current_floor;
    bool going_up;  // Direction of the elevator (true = up, false = down)
    std::vector<Request> requests;  // List of requests (both inside and outside)
    std::queue<Request> pending_requests;  // Requests waiting to be processed

    void processRequests();
    void moveElevator();
    int calculateTimeToServeRequest(const Request& req) const;
};

#endif
