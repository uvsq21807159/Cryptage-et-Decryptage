run : main.o Sommet.o huffman.o
	g++ -o run main.o Sommet.o huffman.o 

main.o: main.cpp huffman.h
	g++ -c main.cpp

huffman.o :huffman.cpp huffman.h Sommet.h
	g++ -c huffman.cpp 

Sommet.o : Sommet.cpp Sommet.h
	g++ -c Sommet.cpp


clean : 
		rm -f *.o
		rm -f run
		rm -f *.h.gch