COMPILE = g++ -std=c++17
DEBUG_FLAG = -g
WARNINGS = -Wall -Wextra -pedantic

.cc.o:
	$(COMPILE) $(DEBUG_FLAG) $(WARNINGS) -c $<

hforest : test_hforest.cc hforest.cc hforest.hh
	$(COMPILE) $(DEBUG_FLAG) $(WARNINGS) test_hforest.cc -o hforest

htree : test_htree.cc htree.cc htree.hh
	$(COMPILE) $(DEBUG_FLAG) $(WARNINGS) test_htree.cc -o htree

clean:
	rm -f *.o
