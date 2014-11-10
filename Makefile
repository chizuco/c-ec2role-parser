
parse:	main.o parser.o
	 gcc main.o parser.o -o parse -ljson-c

main.o: main.c
parser.o: parser.c

.PHONY: clean
clean:
	rm -f parse
	rm -f main.o parser.o

.PHONY: test
test:
	test/test.sh
