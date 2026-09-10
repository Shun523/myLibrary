#include "uf.h"

#include <stdlib.h>

struct UnionFind* uf_create(int n) {
  (void)n;
  return NULL;
}

void uf_destroy(struct UnionFind* uf) { (void)uf; }

int uf_find(struct UnionFind* uf, int x) {
  (void)uf;
  (void)x;
  return 0;
}

void uf_unite(struct UnionFind* uf, int x, int y) {
  (void)uf;
  (void)x;
  (void)y;
}

int uf_same(struct UnionFind* uf, int x, int y) {
  (void)uf;
  (void)x;
  (void)y;
  return 0;
}
