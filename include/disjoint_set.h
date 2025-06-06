#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

typedef struct
{
  int *parent;
  int *size;
  int count;
} DisjointSet;

DisjointSet *create_disjoint_set(int n);
void free_disjoint_set(DisjointSet *ds);
int find(DisjointSet *ds, int x);
void union_sets(DisjointSet *ds, int a, int b);

#endif