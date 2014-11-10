#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    FILE *fin;
    char *filename;

    if (argc < 2) {
        fprintf(stderr, "no filename given\n");
        return 1;
    }

    filename = argv[1];
    struct stat st;

    if (stat(filename, &st) < 0) {
        fprintf(stderr, "unable to stat %s\n", filename);
        return 1;
    }

    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "unable to open file %s", argv[1]);
        return 1;
    }

    char *content;

    content = (char *) malloc(st.st_size);

    if (fread(content, st.st_size, 1, fin) == 0) {
        fprintf(stderr, "unable to open file %s", argv[1]);
        return 1;
    }

    printf("%s", content);

    free(content);
    fclose(fin);
    return 0;
}
