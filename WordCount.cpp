#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	if(argc!=3){
		printf("����ȷ���������3����");
		exit(0);
	} 
    FILE *fp;
    int count = 0;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("���ļ�ʧ��!\n");
        return 0;
    }
    if (argv[1][1] == 'w' || argv[1][1] == 'W')
    {
        char s[500];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("���ʵ���Ŀ�ǣ�%d\n", count);
    }
    else if (argv[1][1] == 'c' || argv[1][1] == 'C') 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) 
				count ++;
        printf("�ַ�����Ŀ��: %d", count);
    }
    fclose(fp);
    return 0;
}

