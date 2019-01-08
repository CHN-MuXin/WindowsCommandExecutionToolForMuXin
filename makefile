# MakeFile
CC = gcc
BIT = x64
WR=windres --target=pe-x86-64  --codepage=0xFDE9 --input-format=rc -O coff
#BIT = x86

OBJS = $(BIT)\main.o $(BIT)\main.res

FUJIAA= -finput-charset=UTF-8 -fexec-charset=UTF-8

FUJIAB= -m64 -Os

main.exe:$(OBJS)
	@echo 生成 $(BIT)\main.exe
	$(CC) -o "$(BIT)\main.exe" $(OBJS) $(FUJIAB)
$(BIT)\main.o:main.c main.h
	@echo 生成 $(BIT)\main.o
	@$(CC) $(FUJIAA) $(FUJIAB) -c main.c -o $(BIT)\main.o
$(BIT)\main.res:main.rc
	$(WR) -i "main.rc" -o "$(BIT)\main.res"
.PHONY:del
del:
	del $(BIT)\*.o