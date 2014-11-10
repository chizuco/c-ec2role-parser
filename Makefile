
parse:	main.o parse.o
	 gcc main.o parse.o -o parse -ljson-c

main.o: main.c
parse.o: parse.c

clean:
	rm -f parse
	rm -f main.o parse.o
