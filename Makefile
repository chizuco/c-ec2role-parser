
parse:	parse.c
	gcc parse.c -o parse -ljson-c

clean:
	rm parse
