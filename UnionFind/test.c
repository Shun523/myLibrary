#include <assert.h>
#include <stdio.h>

#include "uf.h"

int main(void) {
  /* uf_create / uf_destroy: 初期状態の確認 */
  struct UnionFind* uf = uf_create(5);
  assert(uf != NULL);
  assert(uf->n == 5);
  for (int i = 0; i < 5; i++) {
    assert(uf->parent[i] == i);
    assert(uf->rank[i] == 0);
  }
  uf_destroy(uf);

  /* uf_find: 経路圧縮の確認 */
  struct UnionFind* c = uf_create(4);
  c->parent[1] = 0;
  c->parent[2] = 1;
  c->parent[3] = 2; /* 3 -> 2 -> 1 -> 0 */
  assert(uf_find(c, 3) == 0);
  assert(c->parent[3] == 0); /* 圧縮された */
  assert(c->parent[2] == 0);
  uf_destroy(c);

  /* uf_unite / uf_same */
  struct UnionFind* u = uf_create(3);
  assert(uf_same(u, 0, 1) == 0);
  uf_unite(u, 0, 1);
  assert(uf_same(u, 0, 1) == 1);
  uf_unite(u, 1, 2);
  assert(uf_same(u, 0, 2) == 1);
  uf_unite(u, 0, 1);
  assert(uf_same(u, 0, 2) == 1);
  uf_destroy(u);

  puts("all tests passed");
  return 0;
}
