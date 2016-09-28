tester: tester.o nine.o
	g++ -o tester tester.o nine.o

treetrav.o: treetrav.h treetrav.cc
	g++ -c treetrav.cc

tester.o: tester.cc nine.h
	g++ -c tester.cc


clean:
	rm -f *~ *.o tester
