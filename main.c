#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(int argc, char ** argv)
{
    if (argc < 2) {
        fprintf(stderr, "no filename given\n");
        return 1;
    }

    char *content = file_get_contents(argv[1]);
    if (content == NULL) {
        return 1;
    }


    struct Credential crd;
    if (parse_credential(content, &crd) == -1) {
        fprintf(stderr, "unable to parse string as json\n");
        return 1;
    }

    printf("%s\n", crd.accesskeyid);
    printf("%s\n", crd.secretaccesskey);
    printf("%s\n", crd.token);

    free_credential(&crd);
    free(content);

    return 0;
}
