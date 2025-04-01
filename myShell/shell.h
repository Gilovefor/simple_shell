#pragma once
#include <sys/wait.h>
#include <sys/types.h>
//waitpid() and associated macros
#include <unistd.h>
//chdir()
//fork()
//exec()
//pid_t
#include <stdlib.h>
//malloc()
//realloc()
//free()
//exit()
//execvp()
//EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>
//fprintf()
//printf()
//stderr
//getchar()
//perror()
#include <string.h>
//strcmp()
//strtok()

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


void lsh_loop(void);			//shell�Ļ���ѭ��
char* lsh_read_line(void);		//��ȡһ��
char* lsh_read_line(void);
char** lsh_split_line(char* line);	//����ÿһ��
int lsh_launch(char** args);	//shell������

int lsh_cd(char** args);		//cd
int lsh_help(char** args);		//help
int lsh_exit(char** args);		//exit

int lsh_execute(char** args);	//�ж����������

extern const int BUILTIN_COUNT; //ȫ�ֱ����洢�����С
extern char* builtin_str[];
extern int (*builtin_func[]) (char**);
int lsh_num_builtins();



