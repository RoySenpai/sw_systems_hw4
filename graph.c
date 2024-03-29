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

void cmd_build_graph(pnode *head) {
    int inptInt = -1;

    scanf("%d", &inptInt);

    pnode currNode = node_find(*head, inptInt), destNode = NULL;
    pedge prevEdge = NULL;

    while(scanf("%d", &inptInt))
    {
        destNode = node_find(*head, inptInt);

        scanf("%d", &inptInt);

        prevEdge = edge_create(inptInt, destNode, prevEdge);
    }

    currNode->edges = prevEdge;
}

void cmd_insert_node(pnode *head) {
    pnode currNode = NULL, destNode = NULL;
    pedge prevEdge = NULL;

    int inptInt = 0;

    scanf("%d", &inptInt);

    currNode = node_find(*head, inptInt);

    if (*head == NULL)
    {
        *head = node_create(inptInt, NULL);
        currNode = *head;
    }

    else if (currNode != NULL)
        node_remove_edges_from(currNode);

    else
    {
        currNode = node_create(inptInt, NULL);
        node_insert(head, currNode);
    }

    while (scanf("%d", &inptInt) == 1)
    {
        destNode = node_find(*head, inptInt);

        scanf("%d", &inptInt);

        prevEdge = edge_create(inptInt, destNode, prevEdge);
    }

    currNode->edges = prevEdge;
}


void cmd_delete_node(pnode *head) {
    pnode currNode = *head;
    pnode destNode = NULL;

    int inptInt = 0;

    scanf("%d", &inptInt);

    if (currNode->node_num == inptInt)
    {
        *head = currNode->next;
        destNode = currNode;
    }

    else
    {
        while (currNode->next != NULL)
        {
            if (currNode->next->node_num == inptInt)
            {
                destNode = currNode->next;
                currNode->next = currNode->next->next;
                break;
            }

            currNode = currNode->next;
        }
    }

    currNode = *head;

    while (currNode != NULL)
    {
        node_remove_edge_to(currNode, inptInt);
        currNode = currNode->next;
    }

    node_remove_edges_from(destNode);
    free(destNode);
}

void cmd_print_graph(pnode head) {
    pedge currEdge = NULL;

    if (head == NULL)
    {
        printf("The graph is empty!\n");
        return;
    }

    while (head != NULL)
    {
        currEdge = head->edges;

        printf("Node #%d:\n", head->node_num);

        if(currEdge == NULL)
            printf("No edges are coming out from the node.");

        else
        {
            while (currEdge != NULL)
            {
                printf("w(%d,%d) = %d", head->node_num, currEdge->endpoint->node_num, currEdge->weight);
                currEdge = currEdge->next;

                if (currEdge != NULL)
                    printf(", ");
            }
        }

        printf("\n");

        head = head->next;
    }
}

void cmd_delete_graph(pnode *head) {
    pnode currNode = (*head), prevNode = NULL;

    while(currNode != NULL)
    {
        prevNode = currNode;
        currNode = currNode->next;

        node_remove_edges_from(prevNode);

        free(prevNode);
    }
}