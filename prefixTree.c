#include "prefixTree.h"

int main(int argc, char *argv[])
{
	FILE *file;
	struct TrieNode *root;

	if(argc!=2)
	{
		fprintf(stderr, "ERROR: Wrong number of arguments.\n");
		return 1;
	}
	
	file = fopen(argv[1], "r");

	if(file==0)
	{
		fprintf(stderr, "Could not find file: %s. Exiting.\n", argv[1]);
		return 1;
	}

	root = create_tree(file);

	return 0;
}

struct TrieNode *create_tree(FILE *file)
{
	struct TrieNode *root = create_trienode(' ', NULL);
	struct TrieNode *ptr = root;
	char *word = calloc(4000, sizeof(char));
	int character;
	int buffer;
}

struct TrieNode *create_trienode(char c, struct TrieNode *parent)
{
	struct TrieNode *node = malloc(sizeof(struct TrieNode));
	node->c = c;
	node->parent = parent;
	node->children = malloc(26*sizeof(struct TrieNode));
	return node;
}

void destroy_trienode(struct TrieNode *node)
{
	int i;
	
	if(node==NULL) 
	{
		return;
	}
	
	for(i=0; i<26; i++)
	{
		destroy_trienode(node->children[i]);
	}

	free(node->children);
	free(node);
	return;
}
