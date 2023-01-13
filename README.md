# Software Systems Course Assignment 4
### For Computer Science B.Sc. Ariel University

**By Roy Simanovich**

## Description
In this assignment we implemented usage of a directed and weighted graph.
All the nodes of the graph are stored in a linked list and all outcoming
edges of each node are stored each one in a seperated linked list.
The program supports unlimited number of nodes and is very light on memory.
The program depends heavily on dynamic memory allocations and is very strict
about it. Failing to provide a valid input will result a segmentation fault.
The program supports the following operations: Creating a graph with nodes,
inserting new node to the graph and replacing existing node from the graph,
deleting a node from the graph, finding the shortest path between two nodes,
finding a solution to the Traveling Salesman Problem (TSP) for specific nodes
in the graph and printing the graph itself.

### Commands
* **A** – Deleting the existing graph (if there is one) and create a given
number of nodes.
* **n** – Comes after 'A' command, initilize and insert a new node to the
graph: The user enters the node number (in an increasing order) and then
enters the outcoming edges - for each edge the user inputs the edge's endpoint
and the edge's weight.
* **B** – Insert a new node to the graph with given edges. If the node already
exists, it will delete all the outcoming edges from it and replace with the
given edges.
* **D** – Deletes a given node from the graph.
* **P** – Prints a representation of the graph itself: Prints all the nodes and
edges of the graph.
* **S** – Prints the shortest path between two given nodes using Dijsktra's
algorithm.
* **T** – Prints a solution to the Traveling Salesman Problem (TSP) for specific
given nodes.
* **CTRL+Z / EOF** – Deleting the existing graph (if there is one) and exit
the program.


## Requirements
* Linux machine
* gcc

## Building
```
# Cloning the repo to local machine
git clone https://github.com/RoySenpai/sw_systems_hw4.git

# Building all the necessary files & the main programs
make all
```

## Running
```
# Runs the graph program.
./graph
```

### Input and Output examples
* **Example #1:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0
TSP shortest path: 6 
Dijsktra shortest path: 3 
```

* **Example #2:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 B 2 1 3 5 1 T 3 2 1 3 D 2 T 2 3 0
TSP shortest path: 6 
TSP shortest path: 8 
TSP shortest path: 3 
```

* **Example #3:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 B 2 1 3 5 1 T 3 2 1 3 A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 2 2 1
TSP shortest path: 6 
TSP shortest path: 8 
TSP shortest path: 1 
```

* **Example #4:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 T 4 2 1 3 5 B 6 2 3 1 4 T 4 6 1 3 5
TSP shortest path: 6 
TSP shortest path: 7 
TSP shortest path: -1 
```

* **Example #5:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 B 5 0 4 2 1 T 4 2 1 3 5 B 6 2 3 1 4 T 3 1 3 6
TSP shortest path: 6 
TSP shortest path: 7 
TSP shortest path: 9 
```

* **Print Example:**
```
./graph
A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 B 5 0 4 2 1 B 6 2 3 1 4 P
Node #0:
w(0,3) = 3, w(0,2) = 5
Node #1:
w(1,0) = 2, w(1,3) = 7
Node #2:
w(2,1) = 1, w(2,0) = 4
Node #3:
No edges are coming out from the node.
Node #5:
w(5,2) = 1, w(5,0) = 4
Node #6:
w(6,1) = 4, w(6,2) = 3
```