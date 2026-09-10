CC        = cc
CFLAGS    = -std=c11 -Wall -Wextra -g
ASANFLAGS = -fsanitize=address,undefined

test: uf.c test.c uf.h
	$(CC) $(CFLAGS) uf.c test.c -o test
	./test

asan: uf.c test.c uf.h
	$(CC) $(CFLAGS) $(ASANFLAGS) uf.c test.c -o test_asan
	./test_asan

clean:
	rm -f test test_asan

.PHONY: test asan clean
