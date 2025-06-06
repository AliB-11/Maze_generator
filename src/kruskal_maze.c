// kruskal_maze.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "disjoint_set.h"

#define N 10
#define NUM_NODES (N * N)

enum
{
    TOP = 0,
    LEFT = 1,
    BOTTOM = 2,
    RIGHT = 3
};

typedef struct
{
    int u;
    int v;
} Edge;

void shuffle_edges(Edge *edges, int count)
{
    for (int i = count - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Edge temp = edges[i];
        edges[i] = edges[j];
        edges[j] = temp;
    }
}

void add_edge(int mst[NUM_NODES][4], int from, int to)
{
    int dr = (to / N) - (from / N);
    int dc = (to % N) - (from % N);

    if (dr == -1)
    {
        mst[from][TOP] = 1;
        mst[to][BOTTOM] = 1;
    }
    else if (dr == 1)
    {
        mst[from][BOTTOM] = 1;
        mst[to][TOP] = 1;
    }
    else if (dc == -1)
    {
        mst[from][LEFT] = 1;
        mst[to][RIGHT] = 1;
    }
    else if (dc == 1)
    {
        mst[from][RIGHT] = 1;
        mst[to][LEFT] = 1;
    }
}

void generate_kruskal_maze(int mst[NUM_NODES][4])
{
    Edge edges[2 * NUM_NODES];
    int edge_count = 0;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            int node = row * N + col;
            if (col < N - 1)
            {
                edges[edge_count++] = (Edge){node, node + 1};
            }
            if (row < N - 1)
            {
                edges[edge_count++] = (Edge){node, node + N};
            }
        }
    }

    shuffle_edges(edges, edge_count);

    DisjointSet *ds = create_disjoint_set(NUM_NODES);

    for (int i = 0; i < edge_count; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(ds, u) != find(ds, v))
        {
            union_sets(ds, u, v);
            add_edge(mst, u, v);
        }
    }

    free_disjoint_set(ds);
}

int main()
{
    srand((unsigned)time(NULL));

    int mst[NUM_NODES][4] = {0};
    generate_kruskal_maze(mst);

    FILE *f = fopen("../output/mst.txt", "w");
    if (!f)
    {
        perror("Failed to open output/mst.txt");
        return 1;
    }

    for (int i = 0; i < NUM_NODES; i++)
    {
        fprintf(f, "%d %d %d %d\n", mst[i][0], mst[i][1], mst[i][2], mst[i][3]);
    }
    fclose(f);

    printf("Maze generated and saved to output/mst.txt\n");
    return 0;
}
