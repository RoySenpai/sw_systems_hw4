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
#include "graph.h"

int main() {
    /* Contains the list of nodes. */
    pnode nodes_list = NULL;

    /* Needed variables */
    char choice = '\0';
    int ret = 0, dummyvar = 0;

    while (ret != EOF)
    {
        ret = scanf("%c", &choice);

        switch (choice)
        {
            case 'A':
            {
                if (nodes_list != NULL)
                {
                    cmd_delete_graph(&nodes_list);
                    nodes_list = NULL;
                }

                scanf("%d", &dummyvar);

                for (int i = (dummyvar - 1); i >= 0; --i)
                    nodes_list = node_create(i, nodes_list);

                break;
            }

            case 'n':
            {
                cmd_build_graph(&nodes_list);
                break;
            }

            case 'B':
            {
                cmd_insert_node(&nodes_list);
                break;
            }

            case 'D':
            {
                cmd_delete_node(&nodes_list);
                break;
            }

            case 'S':
            {
                cmd_algo_shortest_path(nodes_list);
                break;
            }

            case 'T':
            {
                cmd_algo_TSP(nodes_list);
                break;
            }

            case 'P':
            {
                cmd_print_graph(nodes_list);
                break;
            }

            default: break;
        }
    }

    cmd_delete_graph(&nodes_list);

    return 0;
}