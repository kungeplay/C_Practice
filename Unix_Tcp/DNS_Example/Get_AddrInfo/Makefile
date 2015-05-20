all : ClientGet_AddrInfo ServerGet_AddrInfo
OBJC = ClientGet_AddrInfo.o myreadn_writen.o myerror.o mysock_ntop_host.o
OBJS = myreadn_writen.o myerror.o ServerGet_AddrInfo.o
ClientGet_AddrInfo :$(OBJC) 
			g++ -o ClientGet_AddrInfo $(OBJC)
ServerGet_AddrInfo : $(OBJS) 
			g++ -o ServerGet_AddrInfo $(OBJS)
ClientGet_AddrInfo.o : myunp.h
ServerGet_AddrInfo.o : myunp.h
myreadn_writen.o : myunp.h
myerror.o : myunp.h
mysock_ntop_host.o : myunp.h
.PHONY : clean distclean
clean :  #make clean清除上次的make命令所产生的object文件(后缀为“.o”的文件)及可执行文件
		rm -f *.o
distclean : # make distclean 要清除所有生成的文件
		rm -f *.o ClientGet_AddrInfo ServerGet_AddrInfo
