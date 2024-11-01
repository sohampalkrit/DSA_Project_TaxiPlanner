#include <bits/stdc++.h>
using namespace std;
#include <queue>          // Queue for managing requests by priority
#include <string>         // Required for using strings

// Represents a booking request with passenger ID, requested distance, and request time
class BookingRequest {
public:
    string passengerId;
    int distance;
    long requestTime;

    // Constructor to initialize a booking request with passenger ID, distance, and time
    BookingRequest(string pid, int dist, long time)
        : passengerId(pid), distance(dist), requestTime(time) {}

    // Overload the '<' operator to define priority based on distance and time
    bool operator<(const BookingRequest &other) const {
        // Requests are prioritized by shortest distance; if distances are equal, older requests get priority
        if (distance != other.distance) return distance > other.distance;
        return requestTime > other.requestTime;
    }
};

// A priority queue class to handle booking requests based on priority
class TaxiPriorityQueue {
private:
    priority_queue<BookingRequest> requests; // Queue storing booking requests in prioritized order

public:
    // Adds a new request to the queue
    void addRequest(const BookingRequest &request) {
        requests.push(request);
    }

    // Retrieves the highest priority request from the queue
    BookingRequest getNextRequest() {
        if (!requests.empty()) {
            BookingRequest topRequest = requests.top(); // Get the top request
            requests.pop();                             // Remove it from the queue
            return topRequest;
        }
        throw runtime_error("No requests in queue."); // Exception if the queue is empty
    }
};
