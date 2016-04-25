bookshop: main.o booknode.o fiction.o magazine.o textbook.o
	g++ -o $@ $^

main.o: main.cpp booknode.h fiction.h magazine.h textbook.h
	g++ -c $<

booknode.o: booknode.cpp booknode.h
	g++ -c $<

fiction.o: fiction.cpp fiction.h
	g++ -c $<

magazine.o: magazine.cpp magazine.h
	g++ -c $<

textbook.o: textbook.cpp textbook.h
	g++ -c $<


clean:
	rm -f Project5 *.o

