SRC=main3E.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ -g $(OBJ) -o proj4B

.C.o: $<
	g++ -I. -c $<

clean:
	rm *.o proj4B
