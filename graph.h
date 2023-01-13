/*
 *  Software Systems Course Assignment 4
 *  Copyright (C) 2023  Roy Simanovich

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef GRAPH_
#define GRAPH_

#include <stdbool.h>

/*************************************************
 *************** Structs decleration *************
 *************************************************/

/*
 * Struct:  GRAPH_NODE_
 * Aliases:  node, *pnode
 * --------------------
 * A struct that represents a node.
 *
 *  node_num: node number
 *
 *  seq_num: sequance number of the node
 * 
 *  edges: pointer to the linked list
 *          containing all the edges that
 *          are going out from the node. 
 * 
 *  next: pointer to the next node
 *          in the linked list.
 */
typedef struct GRAPH_NODE_ *pnode;;

/*
 * Struct:  edge_
 * Aliases:  edge, *pedge
 * --------------------
 * A struct that represents an edge.
 *
 *  weight: weight of the edge.
 *
 *  endpoint: pointer to the end point
 *              node of the edge.
 * 
 *  next: pointer to the next edge
 *          in the linked list.
 */
typedef struct edge_ {

    /* Weight of the edge. */
    int weight;

    /* Pointer to the end point node of the edge.*/
    pnode endpoint;

    /* Pointer to the next edge in the linked list.*/
    struct edge_ *next;

} edge, *pedge;

/*
 * Struct:  GRAPH_NODE_
 * Aliases:  node, *pnode
 * --------------------
 * A struct that represents a node.
 *
 *  node_num: node number
 *
 *  seq_num: sequance number of the node
 * 
 *  edges: pointer to the linked list
 *          containing all the edges that
 *          are going out from the node. 
 * 
 *  next: pointer to the next node
 *          in the linked list.
 */
typedef struct GRAPH_NODE_ {

    /* Node number. */
    int node_num;

    /* Sequance number of the node. */
    int seq_num;

    /* Pointer to the linked list containing all the edges that are going out from the node. */
    pedge edges;

    /* Pointer to the next node in the linked list.*/
    struct GRAPH_NODE_ *next;

} node, *pnode;

/*
 * Struct:  qNode_
 * Aliases:  qNode, *pqNode
 * --------------------
 * A struct that represents a node in
 *  a priority queue.
 *
 *  node: a pointer to a node in the graph.
 *
 *  priority: priority queue node's priority.
 * 
 *  next: pointer to the next queue node
 *          in the linked list.
 */
typedef struct qNode_ {

    /* A pointer to a node in the graph. */
	pnode node;

    /* Priority queue node's priority. */
	int priority;

    /* Pointer to the next queue node in the linked list.*/
	struct qNode_ *next;

} qNode, *pqNode;


/*************************************************
 ************** Functions decleration ************
 *************************************************/

/***********       Node functions      ***********/

/*
 * Function:  node_create
 * --------------------
 * Creates a node with given node 
 *  number and the next node in the list.
 *
 *  node_num: node's number.
 *
 *  next: pointer to the next node
 *          in the linked list.
 * 
 * return: pointer to the created node.
 */
pnode node_create(int node_num, pnode next);

/*
 * Function:  node_find
 * --------------------
 * Find a node with a given node number in the
 *  linked list.
 *
 *  node_num: node number to search.
 *
 *  start_point: starting point from where
 *                  to search.
 * 
 * return: pointer to the node if found,
 *          NULL if not found.
 */
pnode node_find(pnode start_point, int node_num);

/*
 * Function:  node_insert
 * --------------------
 * Inserting a node to the linked list
 *  and always ensuring that the list
 *  is sorted.
 *
 *  head: pointer to the head of the list
 *
 *  node_to_insert: the node we want to insert
 *                      to the linked list.
 */
void node_insert(pnode *head, pnode node_to_insert);

/*
 * Function:  node_remove_edges_from
 * --------------------
 * Removes all edges that are going out
 *  from a specific node.
 * 
 *  curretNode: the node which to delete
 *                edges from.
 */
void node_remove_edges_from(pnode curretNode);

/*
 * Function:  node_remove_edge_to
 * --------------------
 * Removes an edge that is going in
 *  to a specific node.
 * 
 *  curretNode: starting point.
 * 
 *  node_num: node number that we want
 *              to remove an edge that
 *              are coming to it.
 * 
 *  return: true if found an edge and
 *              delete it, false otherwise.
 */
bool node_remove_edge_to(pnode curretNode, int node_num);


/***********       Edges functions     ***********/

/*
 * Function:  edge_create
 * --------------------
 * Create a new edge node.
 * 
 *  weight: the weight of the edge.
 * 
 *  endpoint: pointer to the endpoint
 *              node.
 * 
 *  next: pointer to the next edge in
 *          the list.
 * 
 *  return: pointer to the edge.
 */
pedge edge_create(int weight, pnode endpoint, pedge next);


/***********       Graph functions     ***********/

/*
 * Function:  cmd_build_graph
 * --------------------
 * Command 'n' - Build a new node with outcoming
 *  edges from it, and insert it to the graph.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_build_graph(pnode *head);

/*
 * Function:  cmd_insert_node
 * --------------------
 * Command 'B' - Insert a new node and outcoming
 *  edges from it to the graph. If the node already
 *  exists, it also deletes all outcoming edges of
 *  the old node.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_insert_node(pnode *head);

/*
 * Function:  cmd_delete_node
 * --------------------
 * Command 'D' - Deletes a node from the graph,
 *  and deletes all the incoming and outcoming edges.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_delete_node(pnode *head);

/*
 * Function:  cmd_print_graph
 * --------------------
 * Command 'P' - Print all the nodes and edges
 *  of the graph.
 *  NOTICE: Used for self-debugging purpose.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_print_graph(pnode head);

/*
 * Function:  cmd_delete_graph
 * --------------------
 * Deletes the current graph:
 *  deletes all nodes and edges of the graph.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes of the graph.
 */
void cmd_delete_graph(pnode *head);


/***********   Priority Queue functions   ***********/

/*
 * Function:  priortyqueue_create_node
 * --------------------
 * Creates a new Priority Queue node.
 * 
 *  node: a pointer to the node we want to put in
 *          the priority queue node.
 * 
 *  priority: the priority of the node.
 * 
 *  return: a pointer to the priority queue node.
 */
pqNode priortyqueue_create_node(pnode node, int priority);

/*
 * Function:  priortyqueue_pop
 * --------------------
 * Pops the first element in a priority queue.
 * 
 *  node: a pointer to the head of the queue.
 * 
 *  return: a pointer to the node.
 */
pnode priortyqueue_pop(pqNode *head);

/*
 * Function:  priortyqueue_push
 * --------------------
 * Pushes a priority queue node to the priority queue
 *  linked list and sorts it based on the priority.
 * 
 *  head: a pointer to the node we want to put in
 *          the priority queue node.
 * 
 *  queueNode: the priority queue node we want to push.
 */
void priortyqueue_push(pqNode *head, pqNode queueNode);



/***********   Algorithms functions   ***********/

/*
 * Function:  cmd_algo_shortest_path
 * --------------------
 * Command 'S' - Finds the shortest path
 *  between two nodes using Dijkstra's algorithm.
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_algo_shortest_path(pnode head);

/*
 * Function:  cmd_algo_TSP
 * --------------------
 * Command 'T' - Finds a solution to the
 *  Traveling Salesman Problem (TSP) for specific
 *  nodes in the graph.
 *  NOTICE: Very consuming operation, only use up to
 *  6 nodes at once!
 * 
 *  head: pointer to the start of the linked
 *          list of the nodes.
 */
void cmd_algo_TSP(pnode head);


/***********    Auxiliary functions   ***********/

/*
 * Function:  algo_swap
 * --------------------
 * Swaps between two integers.
 *
 *  x: a pointer to the first number.
 *
 *  y: a pointer to the second number.
 */
void algo_swap(int *x, int *y);

/*
 * Function:  algo_dijkstra
 * --------------------
 * Auxiliary function for the shortest path
 *  function. It implements Dijkstra's algorithm
 *  and uses a priority queue to calculate the
 *  shortest path between two nodes.
 *
 *  currNode: the source node.
 *
 *  arr: an array that contains the shortest path
 *          from the source node to all other nodes
 *          in the graph.
 * 
 *  len: passed array length.
 */
void algo_dijkstra(pnode currNode, int *arr, int len);

/*
 * Function:  algo_check_permutations
 * --------------------
 * Auxiliary function for the TSP function. It
 *  uses permutations and Dijkstra's algorithm to
 *  find a solution to the Traveling Salesman Problem.
 *  NOTICE: Very consuming operation, only use up to
 *  6 nodes at once!
 * 
 *  head: a pointer to the head of the linked list
 *          of the nodes.
 *
 *  arr: array that contains all the nodes that
 *          are checked.
 * 
 *  start: start point of the array.
 * 
 *  end: end point of the array.
 * 
 *  numberOfNodes: passed array length.
 * 
 *  res: a pointer to store the result.
 */
void algo_check_permutations(pnode head, int *arr, int start, int end, int numberOfNodes, int *res);

#endif
