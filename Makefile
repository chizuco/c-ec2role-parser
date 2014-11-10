
parse:	main.o parser.o
	 gcc main.o parser.o -o parse -ljson-c

main.o: main.c parser.h
parser.o: parser.c  parser.h

.PHONY: clean
clean:
	rm -f parse
	rm -f main.o parser.o

.PHONY: test
test:
	test/test.sh
