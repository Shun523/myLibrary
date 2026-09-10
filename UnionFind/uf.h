/*
ヘッダーファイルとcソースで分ける文化があるよう
コードが大規模になるとincludeを毎回してコンパイルするのは大変というのが一因らしい

ソースコードはコンパイルしてヘッダーだけ残しておけばヘッダーをincludeしてソースをリンクすれば実装を隠せる
*/
#ifndef UF_H
#define UF_H
struct UnionFind {
  int *parent;
  int *rank;
  int n;
};

struct UnionFind* uf_create(int n);
void uf_destroy(struct UnionFind* uf);
int uf_find(struct UnionFind* uf, int x);
void uf_unite(struct UnionFind* uf, int x, int y);
int uf_same(struct UnionFind* uf, int x, int y);

#endif
