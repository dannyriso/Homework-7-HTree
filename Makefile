CXX = g++
CCFLAGS = -g -std=c++17

.cc.o:
	$(CXX) $(CCFLAGS) -c $<

htree : htree.o
	$(CXX) $(CCFLAGS) -o htree htree.o

clean:
	rm -f *.o
