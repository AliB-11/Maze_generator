#include <stdlib.h>
#include "disjoint_set.h"

DisjointSet *create_disjoint_set(int n)
{
  DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
  ds->count = n;
  ds->parent = (int *)malloc(n * sizeof(int));
  ds->size = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    ds->parent[i] = i;
    ds->size[i] = 1;
  }
  return ds;
}

void free_disjoint_set(DisjointSet *ds)
{
  free(ds->parent);
  free(ds->size);
  free(ds);
}

int find(DisjointSet *ds, int x)
{
  if (ds->parent[x] != x)
  {
    ds->parent[x] = find(ds, ds->parent[x]); // path compression
  }
  return ds->parent[x];
}

void union_sets(DisjointSet *ds, int a, int b)
{
  int root_a = find(ds, a);
  int root_b = find(ds, b);

  if (root_a != root_b)
  {
    if (ds->size[root_a] < ds->size[root_b])
    {
      ds->parent[root_a] = root_b;
      ds->size[root_b] += ds->size[root_a];
    }
    else
    {
      ds->parent[root_b] = root_a;
      ds->size[root_a] += ds->size[root_b];
    }
  }
}
