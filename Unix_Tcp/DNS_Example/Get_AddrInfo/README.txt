ClientGet_AddrInfo文件采用分离式编译
编译步骤如下：
g++ -c ./ClientGet_AddrInfo.cpp # generates ClientGet_AddrInfo.o
g++ -c myerror.cpp 			   # generates myerror.o
g++ -c ./myreadn_writen.cpp      #....
g++ -c mysock_ntop_host.cpp 	   #.....
g++ ClientGet_AddrInfo.o myerror.o myreadn_writen.o mysock_ntop_host.o -o ClientGet_AddrInfo #generates ClientGet_AddrInfo
