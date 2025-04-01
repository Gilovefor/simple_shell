#include "../myShell/shell.h"

/*
shell的基本循环
读取：从标准输入中读取命令。
解析：将命令字符串分为程序和参数。
执行：运行解析后的命令。
*/
void lsh_loop(void) {
	char* line;
	char** args;
	char status;
	
	do {
		printf(">");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
		free(status);
	} while (status);
}