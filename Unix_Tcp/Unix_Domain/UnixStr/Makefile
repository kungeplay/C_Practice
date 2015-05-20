OBJS = myerror.o mysignal.o mysocket_tcp.o ServUnixStr.o #使用变量
OBJC =ClieUnixStr.o myerror.o mysocket_tcp.o
all: ServUnixStr ClieUnixStr
ServUnixStr: $(OBJS)
	g++ $(OBJS) -o ServUnixStr
ClieUnixStr: $(OBJC) 
	g++ $(OBJC) -o ClieUnixStr
ServUnixStr.o: myunp.h		#自动推导功能
myerror.o: myunp.h
mysignal.o: myunp.h
mysocket_tcp.o: myunp.h	
ClieUnixStr.o: myunp.h
.PHONY: clean distclean	#.PHONY意思表示clean是一个"伪目标"，而在rm命令前加了一个小减号的意思是说也许某些文件出现问题，但不要管，继续做后面的事
clean: #清除上次的make命令所产生的object文件（后缀为“.o”的文件）及可执行文件。 
	-rm *.o
distclean:
	rm *.o ServUnixStr ClieUnixStr
