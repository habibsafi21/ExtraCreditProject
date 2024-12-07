// elevator.cpp
#include "elevator.h"
#include <iostream>
#include <queue>

Elevator::Elevator(int total_floors, int elevator_id)
    : total_floors(total_floors), elevator_id(elevator_id), current_floor(0), going_up(true) {}

void Elevator::requestFloor(int from_floor, int to_floor) {
    // This method handles the requests made outside the elevator
    requests.push_back({ from_floor, to_floor, false });
    pending_requests.push({ from_floor, to_floor, false });
}

void Elevator::enterElevator(int from_floor, int to_floor) {
    // This method handles requests made inside the elevator
    requests.push_back({ from_floor, to_floor, true });
}

void Elevator::operate() {
    // This method simulates the elevator's movement and processes requests
    std::cout << "Elevator " << elevator_id << " is now operating." << std::endl;

    // Process all requests
    while (!pending_requests.empty()) {
        processRequests();
        moveElevator();
    }
}

void Elevator::processRequests() {
    if (pending_requests.empty()) return;

    // Take the first request in the queue
    Request current_request = pending_requests.front();
    pending_requests.pop();

    std::cout << "Processing request from floor " << current_request.from_floor
        << " to floor " << current_request.to_floor << std::endl;

    // Simulate the time it takes to process this request
    int time_to_serve = calculateTimeToServeRequest(current_request);
    std::cout << "Time to serve this request: " << time_to_serve << " seconds." << std::endl;
}

void Elevator::moveElevator() {
    if (pending_requests.empty()) return;

    // Move the elevator to the next floor
    Request next_request = pending_requests.front();

    if (next_request.from_floor > current_floor) {
        going_up = true;
        current_floor++;
    }
    else if (next_request.from_floor < current_floor) {
        going_up = false;
        current_floor--;
    }

    std::cout << "Elevator " << elevator_id << " is now at floor " << current_floor << std::endl;
}

int Elevator::calculateTimeToServeRequest(const Request& req) const {
    // For simplicity, assume it takes 1 second per floor traveled
    return std::abs(req.from_floor - req.to_floor);
}

int Elevator::getTotalRequests() const {
    return requests.size();
}

double Elevator::calculateWaitTime() const {
    // Calculate average wait time for all requests
    double total_wait_time = 0;
    for (const auto& req : requests) {
        total_wait_time += std::abs(req.from_floor - req.to_floor);
    }
    return requests.empty() ? 0 : total_wait_time / requests.size();
}