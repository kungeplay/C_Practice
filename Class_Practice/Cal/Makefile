OBJ= Cal.o OperationClass.o OperationAddClass.o OperationMulClass.o OperationDivClass.o OperationSubClass.o OperationFactoryClass.o
HEADFILE=OperationClass.h OperationAddClass.h OperationMulClass.h OperationDivClass.h OperationSubClass.h
Cal:$(OBJ)
	g++  -o Cal $(OBJ) -std=c++0x
Cal.o:OperationClass.h OperationFactoryClass.h
OperationClass.o:OperationClass.h
OperationAddClass.o:OperationAddClass.h	
OperationMulClass.o:OperationMulClass.h
OperationDivClass.o:OperationDivClass.h
OperationSubClass.o:OperationSubClass.h
OperationFactoryClass.o:OperationFactoryClass.h $(HEADFILE)	
.PHONY: clean
clean:
	rm -f *.o
