tester: tester.o treetrav.o
	g++ -o tester tester.o treetrav.o

treetrav.o: treetrav.h treetrav.cc
	g++ -c treetrav.cc

tester.o: tester.cc treetrav.h
	g++ -c tester.cc


clean:
	rm -f *~ *.o tester
