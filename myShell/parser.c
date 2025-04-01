#include "../myShell/shell.h"

//读取一行
char* lsh_read_line(void) {
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char* buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "lsh:allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();
		if (c == EOF || c == '\n') {
			buffer[position] = 'n';
			return buffer;
		}
		else {
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize) {
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "lsh:alloction error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

//分割字符串（进行格式化）
char** lsh_split_line(char* line) {
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char** tokens = malloc(sizeof(char*) * bufsize);
	char* token;

	if (!token) {
		fprintf(stderr, "lsh:alloction error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (1) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "lsh:alloction error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}