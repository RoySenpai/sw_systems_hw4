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
#include "graph.h"

pnode node_create(int node_num, pnode next) {
    pnode new_node = (pnode) malloc(sizeof(node));

    if (new_node == NULL)
    {
        perror("malloc");
        exit(1);
    }

    new_node->node_num = node_num;
    new_node->seq_num = 0;
    new_node->edges = NULL;
    new_node->next = next;

    return new_node;
}

pnode node_find(pnode start_point, int node_num) {
    while (start_point != NULL)
    {
        if (start_point->node_num == node_num)
            return start_point;

        start_point = start_point->next;
    }

    return NULL;
}

void node_insert(pnode *head, pnode node_to_insert) {
    pnode *curr = head;

    while ((*curr)->next != NULL)
    {
        if ((((*curr)->node_num) < (node_to_insert->node_num)) && (((*curr)->next->node_num) > (node_to_insert->node_num)))
        {
            node_to_insert->next = (*curr)->next;
            (*curr)->next = node_to_insert;
            return;
        }

        curr = &((*curr)->next);
    }

    node_to_insert->next = (*curr)->next;
    (*curr)->next = node_to_insert;
}

void node_remove_edges_from(pnode curretNode) {
    pedge curr = curretNode->edges, prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;

        free(prev);
    }
}

bool node_remove_edge_to(pnode curretNode, int node_num) {
    pedge currEdge = curretNode->edges, prevEdge = currEdge;

    if (currEdge != NULL)
    {
        if (currEdge->endpoint->node_num == node_num)
        {
            curretNode->edges = currEdge->next;
            free(prevEdge);
            return true;
        }

        while (currEdge->next != NULL)
        {
            prevEdge = currEdge->next;

            if (currEdge->next->endpoint->node_num == node_num)
            {
                currEdge->next = prevEdge->next;
                free(prevEdge);
                return true;
            }

            currEdge = currEdge->next;
        }
    }

    return false;
}