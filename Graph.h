// Standard header guards to prevent multiple inclusions of the Graph class definition
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>                      // For standard input-output operations
#include <unordered_map>                 // To store the adjacency list as a hash table
#include <vector>                        // To store edges in the adjacency list
#include <queue>                         // Required for the priority queue used in Dijkstra’s algorithm
#include <limits>                        // To set initial distances as "infinity"

using namespace std; // Standard namespace to avoid prefixing with std::

// Class to represent a weighted undirected graph
class Graph {
private:
    // Adjacency list representation where each node points to a vector of (neighbor, weight) pairs
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    // Adds a bidirectional edge between two nodes with a specified weight
    void addEdge(const string &source, const string &destination, int weight) {
        adjList[source].push_back({destination, weight}); // Add edge from source to destination
        adjList[destination].push_back({source, weight}); // Add edge from destination to source (undirected)
    }

    // Implements Dijkstra’s algorithm to find the shortest paths from a starting node
    unordered_map<string, int> dijkstra(const string &start) {
        unordered_map<string, int> distances; // Stores shortest distance from start to each node

        // Initialize all distances to infinity, indicating they are unvisited
        for (const auto &node : adjList) {
            distances[node.first] = numeric_limits<int>::max();
        }
        distances[start] = 0; // Distance to the starting node is 0

        // Priority queue for nodes to explore, sorted by shortest distance found so far
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        pq.push({0, start}); // Begin with the starting node

        // While there are nodes to process
        while (!pq.empty()) {
            int currentDistance = pq.top().first; // Get the distance to the current node
            string currentNode = pq.top().second; // Current node to process
            pq.pop();

            // Skip processing if the current node has already been found with a shorter path
            if (currentDistance > distances[currentNode]) continue;

            // Iterate through all neighbors of the current node
            for (const auto &[neighbor, weight] : adjList[currentNode]) {
                int distance = currentDistance + weight; // Calculate distance to the neighbor

                // Update shortest distance to the neighbor if this path is shorter
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance; // Update distance
                    pq.push({distance, neighbor});  // Push neighbor into the priority queue
                }
            }
        }
        return distances; // Return the map of shortest distances
    }
};

#endif // End of GRAPH_H header guard
