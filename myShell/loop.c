#include "../myShell/shell.h"

/*
shell�Ļ���ѭ��
��ȡ���ӱ�׼�����ж�ȡ���
�������������ַ�����Ϊ����Ͳ�����
ִ�У����н���������
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