#include"../myShell/shell.h"

/*
?	#include "../myShell/shell.h": 包含自定义的shell头文件，可能包含一些函数声明和宏定义。
?	pid_t: 是一个数据类型，用于表示进程ID。
?	fork(): 创建一个子进程。子进程会复制父进程的地址空间，返回值在父进程中是子进程的PID，在子进程中是0，如果失败则返回-1。
?	execvp(char *file, char *const argv[]): 用于执行一个程序。file是要执行的程序名，argv是参数列表。成功时不返回，失败时返回-1。
?	perror(const char *s): 打印错误信息，s是错误信息的前缀。
?	exit(int status): 终止进程，status是返回状态。
?	waitpid(pid_t pid, int *status, int options): 等待指定的子进程结束，pid是子进程ID，status是存储子进程状态的指针，options是选项。
?	WUNTRACED: 选项，表示即使子进程被暂停也返回。
?	WIFEXITED(int status): 宏，检查子进程是否正常退出。
?	WIFSIGNALED(int status): 宏，检查子进程是否被信号中断。
*/

int lsh_launch(char** args) {
	pid_t pid, wpid;
	pid, wpid;
	int status;

	pid = fork();
	if (pid == 0) {
		if (execvp(args[0], args) == 1) {
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) {
		perror("lsh");
	}
	else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}
