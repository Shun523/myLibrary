#include "uf.h"

#include <assert.h>
#include <stdlib.h>

struct UnionFind* uf_create(int n) {
  assert(n > 0);  // n<=0だと予期しない動作になる。エッジケース対策
  struct UnionFind* uf = malloc(sizeof(
      *uf));  // sizeof(StructUnionFind)を入れてたけど*ufを入れれば型変更対策になる
  if (uf == NULL) {
    return NULL;  // mallocは失敗したら基本NULLを返すのでこの処理でOK
                  // Linuxはメモリオーバーでも仮想メモリを確保するためNULLをあまり返さないらしいが、チェックは必要
  }
  uf->parent = malloc(n * sizeof(*uf->parent));
  if (uf->parent == NULL) {
    free(uf);
    return NULL;
  }
  uf->rank = malloc(n * sizeof(*uf->rank));
  if (uf->rank == NULL) {
    free(uf->parent);
    free(uf);
    return NULL;
  }
  uf->n = n;

  for (int i = 0; i < n; i++) {
    uf->parent[i] = i;
    uf->rank[i] = 0;
  }

  return uf;
}

void uf_destroy(struct UnionFind* uf) {
  if (uf == NULL)
    return;  // free(NULL)はOKだがNULL->parentはエラーになるので先に判定
  free(uf->parent);
  free(uf->rank);
  free(uf);
}

int uf_find(struct UnionFind* uf, int x) {
  assert(uf != NULL);
  assert(x >= 0 && x < uf->n);
  if (uf->parent[x] == x) return x;
  return uf->parent[x] = uf_find(uf, uf->parent[x]);  // 再帰処理でコンパクトに
}

void uf_unite(struct UnionFind* uf, int x, int y) {
  assert(uf != NULL);
  assert(x >= 0 && x < uf->n && y >= 0 && y < uf->n);
  int rx = uf_find(uf, x);
  int ry = uf_find(
      uf, y);  // UnionFindでは接続判定ができればよいので根だけ見て効率化
  if (rx == ry) return;
  if (uf->rank[rx] > uf->rank[ry]) {
    uf->parent[ry] = rx;
  } else if (uf->rank[rx] == uf->rank[ry]) {
    uf->parent[ry] = rx;
    uf->rank[rx]++;
  } else {
    uf->parent[rx] = ry;
  }
}

int uf_same(struct UnionFind* uf, int x, int y) {
  if (uf_find(uf, x) == uf_find(uf, y)) return 1;
  return 0;
}
