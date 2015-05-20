OBJC = ClieDaytimeTcp.o mytcp_connect.o mysocket_tcp.o \
		myerror.o mysock_ntop_host.o
OBJS = ServDaytimeTcp.o mydaemon_init.o mysignal.o \
		myerror.o mytcp_listen.o mysocket_tcp.o mysock_ntop.o
.PHONY : all
all: ClieDaytimeTcp ServDaytimeTcp
ClieDaytimeTcp: $(OBJC)
	g++ -o ClieDaytimeTcp $(OBJC) 
ServDaytimeTcp: $(OBJS)
	g++ -o ServDaytimeTcp $(OBJS)
mydaemon_init.o: myunp.h
mysignal.o: myunp.h	
myerror.o: myunp.h
mytcp_listen.o: myunp.h
mysocket_tcp.o: myunp.h
ServDaytimeTcp.o: myunp.h
mysock_ntop.o: myunp.h 	
mysock_ntop_host.o: myunp.h	
mytcp_connect.o: myunp.h
ClieDaytimeTcp.o: myunp.h
.PHONY : clean distclean
clean: #make clean清除上次的make命令所产生的object文件(后缀为“.o”的文件)及可执行文件
	rm -f *.o
distclean: # make distclean 要清除所有生成的文件
	rm -f ClieDaytimeTcp ServDaytimeTcp *.o		
