#include <assert.h>
#include <stdio.h>

#include "uf.h"

int main(void) {
  struct UnionFind* uf = uf_create(5);
  assert(uf != NULL);
  assert(uf->n == 5);
  for (int i = 0; i < 5; i++) {
    assert(uf->parent[i] == i);
    assert(uf->rank[i] == 0);
  }
  uf_destroy(uf);
  puts("Task 4 tests passed");
  return 0;
}