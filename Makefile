
parse:	main.o credential_parser.o
	 gcc main.o credential_parser.o -o parse -ljson-c

main.o: main.c credential_parser.h
credential_parser.o: credential_parser.c  credential_parser.h

.PHONY: clean
clean:
	rm -f parse
	rm -f main.o credential_parser.o

.PHONY: test
test:
	test/test.sh
