#include <iostream>                    // For standard input-output operations
#include <limits>                      // To set initial distances as "infinity"
#include "Graph.h"                     // Graph class to represent city and calculate paths
#include "LinkedList.h"                // Doubly linked list class to store ride history
#include <string>                      // For using string data types
#include <unordered_map>               // To store the list of taxis and their locations

using namespace std; // Standard namespace to avoid prefixing with std::

class TaxiMatchSystem {
private:
    Graph graph;                        // Graph representing the city's roads
    unordered_map<string, string> taxis; // Maps taxi IDs to their current location
    DoublyLinkedList rideHistory;        // Stores completed ride history in a doubly linked list

public:
    // Constructor initializes the system with hardcoded roads and taxis
    TaxiMatchSystem() {
        // Add roads to the graph with weights representing distances between points
        graph.addEdge("A", "B", 5);
        graph.addEdge("A", "C", 10);
        graph.addEdge("B", "D", 7);
        graph.addEdge("B", "E", 8);
        graph.addEdge("C", "F", 3);
        graph.addEdge("D", "E", 4);
        graph.addEdge("D", "G", 6);
        graph.addEdge("E", "H", 5);
        graph.addEdge("F", "I", 7);
        graph.addEdge("G", "H", 2);
        graph.addEdge("H", "I", 9);
        graph.addEdge("A", "I", 12); // Direct path from A to I for variety
        
        // Register taxis with their initial locations
        addTaxi("Taxi1", "A");
        addTaxi("Taxi2", "B");
        addTaxi("Taxi3", "G");
    }

    // Adds a taxi with a given ID at a specified initial location
    void addTaxi(const string &taxiId, const string &location) {
        taxis[taxiId] = location; // Map taxi ID to location in the system
    }

    // Processes a ride request by finding the nearest taxi to the pickup location
    void requestRide(const string &passengerId, const string &pickupLocation, const string &destination) {
        cout << "\n--------------------------------------" << endl;
        cout << "         Processing Ride Request       " << endl;
        cout << "--------------------------------------" << endl;
        
        // Use Dijkstra's algorithm to calculate distances from the pickup location
        auto distances = graph.dijkstra(pickupLocation);

        // Variables to find the nearest taxi
        string nearestTaxi;
        int minDistanceToTaxi = numeric_limits<int>::max(); // Start with maximum possible distance

        // Loop through each registered taxi to find the nearest to the pickup location
        for (const auto &[taxiId, taxiLocation] : taxis) {
            // Ensure the taxi's location is reachable from pickup and compare distances
            if (distances.find(taxiLocation) != distances.end() && distances[taxiLocation] < minDistanceToTaxi) {
                minDistanceToTaxi = distances[taxiLocation];
                nearestTaxi = taxiId; // Update nearest taxi if this one is closer
            }
        }

        // If no taxi was found nearby, output an error message
        if (nearestTaxi.empty()) {
            cout << "\nNo taxis available near " << pickupLocation << "." << endl;
            cout << "--------------------------------------" << endl;
            return;
        }

        // Calculate the distance from the pickup location to the destination
        int distanceToDestination = distances[destination];

        // Output details of the nearest taxi and the requested ride
        cout << "\nNearest Taxi Found!" << endl;
        cout << "Taxi ID          : " << nearestTaxi << endl;
        cout << "Distance to Taxi : " << minDistanceToTaxi << " units" << endl;
        cout << "\nRide Details:" << endl;
        cout << "Pickup Location     : " << pickupLocation << endl;
        cout << "Destination         : " << destination << endl;
        cout << "Distance to Destination: " << distanceToDestination << " units" << endl;

        // Complete the ride, recording it in the ride history
        completeRide(passengerId, pickupLocation, destination, nearestTaxi, distanceToDestination);
        
        cout << "--------------------------------------" << endl;
    }

    // Completes a ride by recording its details in the ride history
    void completeRide(const string &passengerId, const string &pickup, const string &destination, const string &taxiId, int distance) {
        // Add ride to the doubly linked list to maintain history
        rideHistory.addRide(passengerId, pickup, destination, taxiId, distance);
        cout << "\nRide completed successfully and added to history." << endl;
    }

    // Displays all rides recorded in the ride history
    void viewRideHistory() const {
        cout << "\n======================================" << endl;
        cout << "           Ride History               " << endl;
        cout << "======================================" << endl;
        rideHistory.displayRides(); // Calls the display function of the DoublyLinkedList class
        cout << "======================================" << endl;
    }
};

// Main function to run the Taxi Match System
int main() {
    TaxiMatchSystem system; // Initialize system with default data
    int choice;             // Stores user's menu choice
    
    do {
        // Display menu for the user
        cout << "\n======================================" << endl;
        cout << "         Taxi Match System            " << endl;
        cout << "======================================" << endl;
        cout << "1. Request a Ride" << endl;
        cout << "2. View Ride History" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Gather ride request details from the user
            string passengerId, pickupLocation, destination;
            
            cout << "\nEnter Passenger ID: ";
            cin >> passengerId;
            cout << "Enter Pickup Location: ";
            cin >> pickupLocation;
            cout << "Enter Destination Location: ";
            cin >> destination;

            // Process the ride request
            system.requestRide(passengerId, pickupLocation, destination);

        } else if (choice == 2) {
            // View the ride history if user chooses option 2
            system.viewRideHistory();
        } else if (choice == 3) {
            // Exit message for the user when they choose to end the program
            cout << "\nThank you for using the Taxi Match System. Goodbye!" << endl;
        } else {
            // Handle invalid menu inputs
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 3); // Continue until the user chooses to exit

    return 0; // Program ends here
}
