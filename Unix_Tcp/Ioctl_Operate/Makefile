OBJ = mysocket_tcp.o mysock_ntop_host.o myerror.o myget_ifi_info.o Prifinfo.o
Prifinfo: $(OBJ)
	g++ -o Prifinfo $(OBJ)
mysock_ntop_host.o: myunp.h
mysocket_tcp.o: myunp.h
myerror.o: myunp.h
myget_ifi_info.o: myunpifi.h	myunp.h
Prifinfo.o: myunp.h myunpifi.h
.PHONY:clean
clean:
	rm -f *.o	
