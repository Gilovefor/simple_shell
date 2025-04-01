#include "../myShell/shell.h"

char* builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char**) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

// 定义数组大小
const int BUILTIN_COUNT = sizeof(builtin_str) / sizeof(char*);

int lsh_num_builtins() {
	return BUILTIN_COUNT;
}

//cd
int lsh_cd(char** args) {
	if (args[1] == NULL) {
		fprintf(stderr, "lsh: expected argument to。。。。");
	}else{
		if (chdir(args[1]) != 0) {
			perror("lsh");
		}
	}
	return 1;
}

//help
int lsh_help(char** args) {
	int i;
	printf("this is a simple shell");

	for (int i = 0; i < lsh_num_builtins(); i++) {
		printf(" %s\n", builtin_str[i]);
	}
	return 1;
}

//exit
int lsh_exit(char** args) {
	return 0;
}