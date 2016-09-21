tester: tester.o nine.o
	g++ -o tester tester.o nine.o

nine.o: nine.h nine.cc
	g++ -c nine.cc

tester.o: tester.cc nine.h
	g++ -c tester.cc


clean:
	rm -f *~ *.o tester
