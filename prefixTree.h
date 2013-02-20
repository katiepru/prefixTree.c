#ifndef _PREFIXTREE_H
#define _PREFIXTREE_H 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

char *strdup(const char *str);

struct TrieNode create_tree(FILE *file);
struct TrieNode create_trienode(char c, struct TrieNode parent);

void destroy_trienode(struct TrieNode *node);

#endif

typedef struct TrieNode
{
	char c;
	struct TrieNode *parent;
	struct TrieNode *children[26];
} TrieNode;

typedef enum {false, true} bool;
