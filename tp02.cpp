#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Struct to represent an one-way road between two cities and their road's capacity
struct Edge {
    int originNode;
    int destinationNode;
    int maxWeight;

    // Operator overloading to compare two edges based on their weights
    bool operator<(const Edge& another) const
    {
        return maxWeight < another.maxWeight;
    }
};

int getCapacitiesFromNode(int originNode, int destinationNode, vector<vector<Edge>> & adjacencyList, vector<vector<int>> & capacities) {
    // Initialize priority queue with all edges from originNode and update the capacities matrix
    vector<bool> visited(capacities.size(), false);
    priority_queue<Edge> pq;
    int maxCapacity = 0;

    visited[originNode] = true;
    capacities[originNode][originNode] = 100000;

    for (int i = 0; i < adjacencyList[originNode].size(); i++) {
        Edge edge = adjacencyList[originNode][i];
        capacities[originNode][edge.destinationNode] = edge.maxWeight;
        pq.push(edge);
    }

    // While there are edges in the priority queue and the destination node has not been visited, continue
    while (!pq.empty()) {
        // Get the edge with the maximum weight
        Edge edge = pq.top();
        pq.pop();
        
        // If the node has already been visited, ignore it
        if (edge.destinationNode == originNode || visited[edge.destinationNode]) {
            continue;
        }

        // Update the capacities matrix at the destination node's index
        if (edge.maxWeight > capacities[originNode][edge.destinationNode]) {
            capacities[originNode][edge.destinationNode] = min(capacities[originNode][edge.originNode], edge.maxWeight);
        }        
        
        // Arrived at destination node
        if (edge.destinationNode == destinationNode) {
            maxCapacity = capacities[originNode][edge.destinationNode];
            return maxCapacity;
        }

        // Add edges to priority queue
        visited[edge.destinationNode] = true;
        for (int i = 0; i < adjacencyList[edge.destinationNode].size(); i++) {
            Edge nextEdge = adjacencyList[edge.destinationNode][i];
            
            pq.push(nextEdge);
        }
    }  
    return maxCapacity;
}

int main() {
    int numberOfCities;
    int numberOfRoads;
    int numberOfQueries;

    // Get the number of cities, roads and queries
    cin >> numberOfCities >> numberOfRoads >> numberOfQueries;
    vector<vector<Edge>> adjacencyList(numberOfCities + 1);

    // Get the roads and their capacities, creating the adjacency list 
    for (int i = 0; i < numberOfRoads; i++)
    {
        Edge aux;
        cin >> aux.originNode >> aux.destinationNode >> aux.maxWeight;
        adjacencyList[aux.originNode].push_back(aux);
    }
    
    // Get the queries and print their results
    vector<bool> nodesAlreadyCalculated(numberOfCities + 1, false);
    vector<vector<int>> capacities(numberOfCities + 1, vector<int>(numberOfCities + 1, 0));
    for (int i = 0; i < numberOfQueries; i++) {
        int originNode;
        int destinationNode;
        
        cin >> originNode >> destinationNode;
        
        int maxCapacity = getCapacitiesFromNode(originNode, destinationNode, adjacencyList, capacities);

        cout << maxCapacity << endl;
    }
    
    return 0;
}