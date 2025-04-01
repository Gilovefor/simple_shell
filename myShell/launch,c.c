#include"../myShell/shell.h"

/*
?	#include "../myShell/shell.h": �����Զ����shellͷ�ļ������ܰ���һЩ���������ͺ궨�塣
?	pid_t: ��һ���������ͣ����ڱ�ʾ����ID��
?	fork(): ����һ���ӽ��̡��ӽ��̻Ḵ�Ƹ����̵ĵ�ַ�ռ䣬����ֵ�ڸ����������ӽ��̵�PID�����ӽ�������0�����ʧ���򷵻�-1��
?	execvp(char *file, char *const argv[]): ����ִ��һ������file��Ҫִ�еĳ�������argv�ǲ����б��ɹ�ʱ�����أ�ʧ��ʱ����-1��
?	perror(const char *s): ��ӡ������Ϣ��s�Ǵ�����Ϣ��ǰ׺��
?	exit(int status): ��ֹ���̣�status�Ƿ���״̬��
?	waitpid(pid_t pid, int *status, int options): �ȴ�ָ�����ӽ��̽�����pid���ӽ���ID��status�Ǵ洢�ӽ���״̬��ָ�룬options��ѡ�
?	WUNTRACED: ѡ���ʾ��ʹ�ӽ��̱���ͣҲ���ء�
?	WIFEXITED(int status): �꣬����ӽ����Ƿ������˳���
?	WIFSIGNALED(int status): �꣬����ӽ����Ƿ��ź��жϡ�
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
