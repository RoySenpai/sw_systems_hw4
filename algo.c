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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "graph.h"

pqNode priortyqueue_create_node(pnode node, int priority) {
    pqNode new_queue_node = (pqNode) malloc(sizeof(qNode));

	if (new_queue_node == NULL)
	{
		perror("malloc");
		exit(errno);
	}

    new_queue_node->node = node;
    new_queue_node->priority = priority;
    new_queue_node->next = NULL;

    return new_queue_node;
}

pnode priortyqueue_pop(pqNode *head) {
	if (*(head) == NULL)
		return NULL;

    pqNode popedQueueNode = *head;
    pnode popedNode = (*head)->node;

    (*head) = (*head)->next;

    free(popedQueueNode);

    return popedNode;
}

void priortyqueue_push(pqNode *head, pqNode queueNode) {
	if ((*head) == NULL)
	{
		(*head) = queueNode;
		return;
	}

	else if (((*head)->priority) > (queueNode->priority))
	{
		queueNode->next = *head;
		*head = queueNode;
		return;
	}

	pqNode curr = *head;

	while (curr->next != NULL)
	{
		if ((curr->next->priority) >= (queueNode->priority))
			break;

		curr = curr->next;
	}

	queueNode->next = curr->next;
	curr->next = queueNode;
}

void cmd_algo_shortest_path(pnode head) {
	pnode currNode = head, prevNode = NULL;
	int *dijkstraArr = NULL;
	int src = 0, dest = 0, numberOfNodes = 0, dsrc = 0, ddest = 0;

	scanf("%d%d", &src, &dest);

	while (currNode != NULL)
	{
		currNode->seq_num = numberOfNodes;

		if (currNode->node_num == src)
		{
			prevNode = currNode;
			dsrc = numberOfNodes;
		}

		if (currNode->node_num == dest)
			ddest = numberOfNodes;

		currNode = currNode->next;
		++numberOfNodes;
	}

	dijkstraArr = (int*) malloc(numberOfNodes * sizeof(int));

	if (dijkstraArr == NULL)
	{
		perror("malloc");
		exit(errno);
	}

	for (int i = 0; i < numberOfNodes; ++i)
		*(dijkstraArr + i) = INT_MAX;

	*(dijkstraArr + dsrc) = 0;

	algo_dijkstra(prevNode, dijkstraArr, numberOfNodes);

	printf("Dijsktra shortest path: %d \n", (*(dijkstraArr + ddest) < INT_MAX) ? *(dijkstraArr + ddest):-1);

	free(dijkstraArr);
}

void cmd_algo_TSP(pnode head) {
	pnode currNode = head;
	int *TSP_cities = NULL;
	int numberOfCities = 0, totalNodes = 0, res = INT_MAX;

	scanf("%d", &numberOfCities);

	TSP_cities = (int*) malloc(numberOfCities * sizeof(int));

	if (TSP_cities == NULL)
	{
		perror("malloc");
		exit(errno);
	}

	for (int i = 0; i < numberOfCities; ++i)
		scanf("%d", &(*(TSP_cities+i)));

	while (currNode != NULL)
	{
		currNode->seq_num = totalNodes++;
		currNode = currNode->next;
	}

	algo_check_permutations(head, TSP_cities, 0, (numberOfCities - 1), totalNodes, &res);

	printf("TSP shortest path: %d \n", (res < INT_MAX) ? res:-1);

	free(TSP_cities);
}

void algo_swap(int *x, int *y) {
	int temp = *x;
    *x = *y;
    *y = temp;
}

void algo_dijkstra(pnode currNode, int *arr, int len) {
	pqNode queue_first_node = priortyqueue_create_node(currNode, 1);
	pqNode* pQueue = &queue_first_node;
	pedge currEdge = NULL;

	while ((*pQueue) != NULL)
	{
		currNode = priortyqueue_pop(pQueue);
		currEdge = currNode->edges;

		while (currEdge != NULL)
		{
			if (((*(arr + currNode->seq_num) + currEdge->weight) < *(arr + currEdge->endpoint->seq_num)))
			{
				*(arr + currEdge->endpoint->seq_num) = *(arr + currNode->seq_num) + currEdge->weight;
				priortyqueue_push(pQueue, priortyqueue_create_node(currEdge->endpoint, *(arr + currEdge->endpoint->seq_num)));
			}

			currEdge = currEdge->next;
		}
	}
}

void algo_check_permutations(pnode head, int *arr, int start, int end, int numberOfNodes, int *res) {
	if (start != end)
	{
		for (int i = start; i <= end; ++i)
		{
			algo_swap((arr + start), (arr+i));
			algo_check_permutations(head, arr, (start + 1), end, numberOfNodes, res);
			algo_swap((arr + start), (arr+i));
		}

		return;
	}

	pnode currNode = node_find(head, *arr);

	int dummyvar = 0;
	int *dijkstraArr = (int *)malloc(numberOfNodes * sizeof(int));

	if (dijkstraArr == NULL)
	{
		perror("malloc");
		exit(errno);
	}

	for (int i = 1; i <= end; ++i)
	{
		pnode searchNode = node_find(head, *(arr + i));

		for (int j = 0; j < numberOfNodes; ++j)
			*(dijkstraArr + j) = INT_MAX;

		*(dijkstraArr + currNode->seq_num) = 0;

		algo_dijkstra(currNode, dijkstraArr, numberOfNodes);

		if (*(dijkstraArr + (searchNode->seq_num)) == INT_MAX)
		{
			free(dijkstraArr);
			return;
		}

		currNode = node_find(head, *(arr + i));

		dummyvar += *(dijkstraArr + currNode->seq_num);
	}

	free(dijkstraArr);

	if (dummyvar < *res && dummyvar != 0)
		*res = dummyvar;
}