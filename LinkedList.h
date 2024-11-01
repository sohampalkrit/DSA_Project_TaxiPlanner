#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>       // For displaying ride information
#include <string>         // For storing string data like IDs and locations

using namespace std;

// Struct for storing details of each completed ride in a doubly linked list
struct RideNode {
    string passengerId;
    string pickup;
    string destination;
    string taxiId;
    int distance;
    RideNode *next;
    RideNode *prev;

    // Initialize a RideNode with details of the ride
    RideNode(string pid, string p, string d, string t, int dist)
        : passengerId(pid), pickup(p), destination(d), taxiId(t), distance(dist), next(nullptr), prev(nullptr) {}
};

// Doubly linked list to maintain ride history
class DoublyLinkedList {
private:
    RideNode *head; // Pointer to the start of the list

public:
    // Constructor initializes the head to null
    DoublyLinkedList() : head(nullptr) {}

    // Adds a new ride to the list (end of the list for chronological order)
    void addRide(const string &passengerId, const string &pickup, const string &destination, const string &taxiId, int distance) {
        RideNode *newNode = new RideNode(passengerId, pickup, destination, taxiId, distance);
        if (!head) { // If list is empty, new node becomes head
            head = newNode;
        } else {
            RideNode *temp = head;
            while (temp->next) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newNode;  // Attach the new node at the end
            newNode->prev = temp;  // Set backward link
        }
    }

    // Display all rides stored in the list
    void displayRides() const {
        RideNode *temp = head;
        if (!temp) { // If no rides in history, show a message
            cout << "No rides in history." << endl;
            return;
        }
        // Traverse the list and print each ride
        while (temp) {
            cout << "Passenger ID: " << temp->passengerId
                 << ", Pickup: " << temp->pickup
                 << ", Destination: " << temp->destination
                 << ", Taxi ID: " << temp->taxiId
                 << ", Distance Traveled: " << temp->distance << " units" << endl;
            temp = temp->next;
        }
    }
};

#endif // End of DOUBLYLINKEDLIST_H header guard
