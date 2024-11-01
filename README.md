# Taxi Match System

## Table of Contents
1. [Introduction](#introduction)
2. [System Design](#system-design)
   - [Objective](#objective)
   - [Functional Requirements](#functional-requirements)
3. [Modules Overview](#modules-overview)
   - [Graph Module](#graph-module)
   - [Booking Request and Taxi Priority Queue](#booking-request-and-taxi-priority-queue)
   - [Ride History (Doubly Linked List)](#ride-history-doubly-linked-list)
   - [TaxiMatchSystem (Main Controller)](#taximatchsystem-main-controller)
4. [Key Algorithms and Data Structures](#key-algorithms-and-data-structures)
   - [Dijkstra's Algorithm for Shortest Path](#dijkstras-algorithm-for-shortest-path)
   - [Priority Queue for Ride Requests](#priority-queue-for-ride-requests)
   - [Doubly Linked List for Ride History](#doubly-linked-list-for-ride-history)
5. [Detailed Code Explanation](#detailed-code-explanation)
   - [Graph Class](#graph-class)
   - [BookingRequest and TaxiPriorityQueue Classes](#bookingrequest-and-taxipriorityqueue-classes)
   - [DoublyLinkedList Class](#doublylinkedlist-class)
   - [TaxiMatchSystem Class](#taximatchsystem-class)
6. [User Interface Design and User Flow](#user-interface-design-and-user-flow)
7. [Testing and Validation](#testing-and-validation)
8. [Future Enhancements](#future-enhancements)
9. [Conclusion](#conclusion)
10. [User Manual](#user-manual)

## Introduction

The **Taxi Match System** is designed to simulate a ride-hailing platform that finds the nearest available taxi to a passenger's pickup location and calculates the shortest route to their destination. The system includes modules for maintaining a map of locations, storing taxi locations, processing ride requests, and tracking ride history. This README outlines the system's structure, code implementation, testing, and potential future enhancements.

## System Design

### Objective
The objective of the Taxi Match System is to provide a framework to:
- **Calculate** the shortest path from a pickup location to a destination.
- **Identify** and **assign** the nearest available taxi to the passenger.
- **Track** and **store** completed rides for historical reference.

### Functional Requirements
The system includes the following primary functionalities:
- **Request a Ride:** Identifies the nearest taxi to a given pickup location and assigns it to the passenger.
- **View Ride History:** Displays all completed rides with relevant details.
- **Exit:** Allows the user to exit the application gracefully.

## Modules Overview

The system is modular, consisting of several key components:

### Graph Module
- **Purpose:** Models the city map using a graph structure, where locations are nodes, and roads are edges with weights representing distances.
- **Core Functionality:** Implements Dijkstra's algorithm to calculate the shortest paths from any given node to other nodes in the graph.

### Booking Request and Taxi Priority Queue
- **Purpose:** Manages ride requests based on passenger information, distance, and request time.
- **Core Functionality:** Utilizes a priority queue to prioritize requests based on proximity and request time, ensuring that the nearest taxi is assigned first.

### Ride History (Doubly Linked List)
- **Purpose:** Tracks and stores completed rides.
- **Core Functionality:** Uses a doubly linked list structure for efficient addition and traversal, enabling a detailed record of ride history.

### TaxiMatchSystem (Main Controller)
- **Purpose:** Acts as the main control system coordinating taxi assignments, distance calculations, and ride history tracking.
- **Core Functionality:** Combines the functionalities of other modules, handles user interaction, and facilitates system processes such as ride requests, taxi matching, and ride history display.

## Key Algorithms and Data Structures

### Dijkstra's Algorithm for Shortest Path
- **Objective:** Finds the shortest path between nodes in the graph, used to determine the shortest routes from pickup locations to destinations.
- **Implementation:** Uses a priority queue to explore nodes based on the current shortest distance, continually updating distances to neighboring nodes.

### Priority Queue for Ride Requests
- **Objective:** Prioritizes ride requests based on the shortest distance to available taxis and request time.
- **Implementation:** A priority queue container prioritizes requests, ensuring that the nearest taxis are assigned to passengers in the order of their requests.

### Doubly Linked List for Ride History
- **Objective:** Stores and retrieves ride records efficiently, allowing the system to log completed rides and enable user access to ride history.
- **Implementation:** Each node in the doubly linked list represents a completed ride with details, including the passenger ID, pickup and destination locations, taxi ID, and distance.

## Detailed Code Explanation

### Graph Class
This class defines the graph structure, with methods to add edges and perform Dijkstra’s algorithm. The graph is represented by an adjacency list with distances (weights) as edge weights.

### BookingRequest and TaxiPriorityQueue Classes
- **BookingRequest Class:** Encapsulates details about each ride request.
- **TaxiPriorityQueue Class:** Manages these requests in a priority queue, ensuring the system can retrieve requests in order of priority.

### DoublyLinkedList Class
This class maintains the ride history using a doubly linked list. Each node in the list is a **RideNode** that holds details of a completed ride.

### TaxiMatchSystem Class
This class serves as the main controller, initializing the graph and taxis, processing ride requests, and updating ride history.

## User Interface Design and User Flow

The user interface consists of a command-line menu that allows users to:
- **Request a Ride:** Prompted to enter passenger ID, pickup location, and destination.
- **View Ride History:** Displays all completed rides with relevant details.
- **Exit the System:** Terminates the application.

## Testing and Validation

The following tests ensure the reliability and accuracy of the system:
- **Shortest Path Calculation:** Verified by checking calculated routes for known distances.
- **Nearest Taxi Selection:** Tested by placing taxis at various locations to ensure the nearest one is selected for a request.
- **Ride History Logging:** Ensured all completed rides are stored and displayed accurately.

## Future Enhancements

The system could be further enhanced by adding:
- **Real-Time Location Updates:** Enabling taxis to update their locations dynamically.
- **Multiple Pickup Options:** Allowing for carpooling by matching multiple passengers to a single taxi.
- **Graphical User Interface (GUI):** Enhancing usability with a visual interface for users to select locations and track rides.

## Conclusion

The **Taxi Match System** successfully models a simplified ride-hailing platform by employing graph-based shortest path calculations, priority queue-based taxi selection, and doubly linked list storage for ride history. This project demonstrates an effective approach to combining data structures and algorithms to meet real-world application needs and provides a solid foundation for further enhancements in ride-matching systems.

## User Manual

The Taxi Match System allows users to manage ride requests easily. Here’s how to interact with the application:

### Running the Application
1. Compile the code using a C++ compiler with C++17 support.
2. Run the executable generated after compilation.

### Available Options
1. **Request a Ride:** When prompted, enter the following details:
   - **Passenger ID:** Unique identifier for the passenger.
   - **Pickup Location:** The location where the passenger wants to be picked up.
   - **Destination:** The location where the passenger wants to go.

2. **View Ride History:** This option displays all completed rides with their details, including passenger ID, pickup and destination locations, taxi ID, and distance traveled.

3. **Exit:** This option allows the user to exit the application gracefully.

### User Flow Example
- Upon starting the application, the user is presented with a menu.
- If the user selects "1" to request a ride, they will be prompted to input their Passenger ID, pickup location, and destination.
- The system calculates the nearest taxi and the distance to the destination, completing the ride and adding it to the ride history.
- If the user selects "2", the application displays all rides recorded in history.
- Choosing "3" exits the application.

For further assistance, please refer to the code comments and documentation.
