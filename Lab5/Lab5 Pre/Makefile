CXX=clang++ 
CXXFLAGS=-Wall # Enable all warnings                                            
DEBUG=-g

OFILES = TreeCalc.o TreeNode.o TreeCalcTest.o

.SUFFIXES: .o .cpp

.PHONY: main clean

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)


clean:
	-rm *.o a.out





