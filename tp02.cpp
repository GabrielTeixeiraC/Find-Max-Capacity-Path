#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int originNode;
    int destinationNode;
    int maxWeight;

    bool operator<(const Edge& another) const
    {
        return maxWeight < another.maxWeight;
    }
};

void getCapacitiesFromNode(int originNode, vector<vector<Edge>> & adjacencyList, vector<vector<int>> & capacities) {
    vector<bool> visited(capacities.size(), false);
    priority_queue<Edge> pq;

    visited[originNode] = true;
    capacities[originNode][originNode] = 100000;
    for (int i = 0; i < adjacencyList[originNode].size(); i++) {
        Edge edge = adjacencyList[originNode][i];
        capacities[originNode][edge.destinationNode] = edge.maxWeight;
        pq.push(edge);
    }

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        if (edge.maxWeight > capacities[originNode][edge.destinationNode]) {
            capacities[originNode][edge.destinationNode] = min(capacities[originNode][edge.originNode], edge.maxWeight);
        }        

        visited[edge.destinationNode] = true;
        for (int i = 0; i < adjacencyList[edge.destinationNode].size(); i++) {
            Edge nextEdge = adjacencyList[edge.destinationNode][i];
            if (nextEdge.destinationNode == originNode || visited[nextEdge.destinationNode]) {
                continue;
            }
            
            pq.push(nextEdge);
        }
    }  
    return;
}

int main() {
    int numberOfCities;
    int numberOfRoads;
    int numberOfQueries;

    cin >> numberOfCities >> numberOfRoads >> numberOfQueries;
    vector<vector<Edge>> adjacencyList(numberOfCities + 1);

    for (int i = 0; i < numberOfRoads; i++)
    {
        Edge aux;
        cin >> aux.originNode >> aux.destinationNode >> aux.maxWeight;
        adjacencyList[aux.originNode].push_back(aux);
    }
    
    vector<bool> nodesAlreadyCalculated(numberOfCities + 1, false);
    vector<vector<int>> capacities(numberOfCities + 1, vector<int>(numberOfCities + 1, 0));
    for (int i = 0; i < numberOfQueries; i++) {
        int originNode;
        int destinationNode;
        
        cin >> originNode >> destinationNode;
        
        if (!nodesAlreadyCalculated[originNode]) {

            getCapacitiesFromNode(originNode, adjacencyList, capacities);
        }
        
        if (i != numberOfQueries - 1) {
            cout << capacities[originNode][destinationNode] << endl;
        }
        else {
            cout << capacities[originNode][destinationNode];
        }
        
    }
    
    return 0;
}