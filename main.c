#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//#include "main.h"

int execmd(char* cmd,char* result) {
    char buffer[4096];                         //定义缓冲区                        
    FILE* pipe = _popen(cmd, "r");            //打开管道，并执行命令 
    if (!pipe)
          return 0;                      //返回0表示运行失败 
        
    while(!feof(pipe)) {
    if(fgets(buffer, 4096, pipe)){             //将管道输出到result中 
            strcat(result,buffer);
        }
    }
    _pclose(pipe);                            //关闭管道 
    return 1;                                 //返回1表示运行成功 
}

int main(int argc,char **argv) {
	setlocale(LC_CTYPE, "");
	_wsystem(L"title 文本命令执行工具 By沐心");
	char cmd[4096],ret[4096],fileName[1024];
	FILE* file;
	wprintf(L"\n========================================\n");
	wprintf(L"           程序说明\n");
	wprintf(L"    本程序用来执行cmd命令名命令\n");
	wprintf(L"本程序的原理就是将文件中的文本交给系统处理\n");
	wprintf(L"文本是什么编码的程序就原封不动交给系统处理\n");
	wprintf(L"所以可用来执行传递一些特定编码参数的命令\n");
	wprintf(L"========================================\n");
	start:
	cmd[0] = ret[0] = fileName[0] = '\0';
	file=NULL;
	wprintf(L"\n请输入文件名：\n");
	scanf("%s",fileName);
	wprintf(L"您输入的文件名%S\n",fileName);
	file =  fopen(fileName,"r");
	if(file != NULL){
		wprintf(L"成功打开文件：%S\n",fileName);
		if(fgets(cmd,4096,file) > 0){
			if(execmd(cmd,ret)){
				wprintf(L"执行成功 %S %S \n",cmd,ret);
			}else{
				wprintf(L"执行失败！\n");
			}
		}
		fclose(file);
	}else{
		wprintf(L"打开文件 %S 失败！\n",fileName);
	}
	goto start;
	return 0;
}






