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

	destroy_trienode(root);

	return 0;
}

