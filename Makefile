
parse:	main.o ec2role_parser.o
	 gcc main.o ec2role_parser.o -o parse -ljson-c

main.o: main.c ec2role_parser.h
ec2role_parser.o: ec2role_parser.c  ec2role_parser.h

.PHONY: clean
clean:
	rm -f parse
	rm -f main.o ec2role_parser.o

.PHONY: test
test:
	test/test.sh
