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

pedge edge_create(int weight, pnode endpoint, pedge next) {
    pedge new_edge = (pedge) malloc(sizeof(edge));

    if (new_edge == NULL)
    {
        perror("malloc");
        exit(1);
    }

    new_edge->weight = weight;
    new_edge->endpoint = endpoint;
    new_edge->next = next;

    return new_edge;
}
