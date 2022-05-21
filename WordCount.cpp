#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	if(argc!=3){
		printf("请正确输入参数（3个）");
		exit(0);
	} 
    FILE *fp;
    int count = 0;
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("打开文件失败!\n");
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
        printf("单词的数目是：%d\n", count);
    }
    else if (argv[1][1] == 'c' || argv[1][1] == 'C') 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) 
				count ++;
        printf("字符的数目是: %d", count);
    }
    fclose(fp);
    return 0;
}

