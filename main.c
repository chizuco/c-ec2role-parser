#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "aws_credential.h"

char *file_get_contents(const char *filename)
{
    FILE *fin;
    struct stat st;

    if (stat(filename, &st) < 0) {
        fprintf(stderr, "unable to stat %s\n", filename);
        return NULL;
    }

    fin = fopen(filename, "r");
    if (fin == NULL) {
        fprintf(stderr, "unable to open file %s", filename);
        return NULL;
    }

    char *content;

    content = (char *) malloc(st.st_size);
    if (fread(content, st.st_size, 1, fin) == 0) {
        fprintf(stderr, "unable to open file %s", filename);
        return NULL;
    }

    fclose(fin);

    return content;
}


int main(int argc, char ** argv)
{
    if (argc < 2) {
        fprintf(stderr, "no filename given\n");
        return 1;
    }

    char *json_string = file_get_contents(argv[1]);
    if (json_string == NULL) {
        return 1;
    }


    struct Credential crd;
    if (parse_credential_json(json_string, &crd) == -1) {
        fprintf(stderr, "unable to parse string as json\n");
        return 1;
    }

    printf("%s\n", crd.accesskeyid);
    printf("%s\n", crd.secretaccesskey);
    printf("%s\n", crd.token);

    free_credential(&crd);
    free(json_string);

    return 0;
}
