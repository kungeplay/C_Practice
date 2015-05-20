OBJ = ServDaytimeTcpInetd.o mydaemon_inetd.o myerror.o mysocket_tcp.o mysock_ntop.o
ServDaytimeTcpInetd: $(OBJ)
	g++ -o ServDaytimeTcpInetd $(OBJ)
ServDaytimeTcpInetd.o: myunp.h
mydaemon_inetd.o: myunp.h
myerror.o: myunp.h
mysocket_tcp.o: myunp.h
mysock_ntop.o: myunp.h	
.PHONY: clean
clean:
	rm -f *.o