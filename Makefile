
parse:	main.o aws_credential.o
	 gcc main.o aws_credential.o -o parse -ljson-c

main.o: main.c aws_credential.h
aws_credential.o: aws_credential.c  aws_credential.h

.PHONY: clean
clean:
	rm -f parse
	rm -f main.o aws_credential.o

.PHONY: test
test:
	test/test.sh
