# Find Max Capacity Path
This greedy algorithm outputs the maximum capacity between two given nodes in a graph given a list of edges and its weights. The input must be in the format:

    <number of nodes> <number of edges> <number of queries>
    <node 1> <node 2> <capacity>
    ... other edges
    <node 1> <node 2>
    ... other queries

## Example 1:

### Input: 
    9 14 1
    1 2 2500
    2 3 4000
    1 4 3000
    2 5 3000
    5 2 1500
    3 6 1200
    4 5 1000
    5 6 1500
    4 7 1600
    5 8 2000
    8 5 3000
    6 9 1700
    7 8 1000
    8 9 1500
    1 9

### Output
    1500

## Example 2:

### Input: 
    4 10 4
    1 2 9000
    2 1 9000
    1 3 1000
    3 1 1000
    2 3 8000
    3 2 8000
    2 4 7000
    4 2 7000
    3 4 4000
    4 3 4000
    1 4
    2 1
    3 1
    4 3

### Output
    7000
    9000
    8000
    7000
