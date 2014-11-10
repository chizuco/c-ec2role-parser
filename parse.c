#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>

struct Credential
{
    const char *accesskeyid;
    const char *token;
    const char *secretaccesskey;
};


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


void free_credential(struct Credential *crd)
{
    free((void *)crd->accesskeyid);
    free((void *)crd->token);
    free((void *)crd->secretaccesskey);

    crd->accesskeyid = NULL;
    crd->token = NULL;
    crd->secretaccesskey = NULL;
}

void parse_credential(const char *json_string, struct Credential *crd)
{
    struct json_object *obj = json_tokener_parse(json_string);

    json_object_object_foreach(obj, key, val) {
        if (strcmp(key, "AccessKeyId") == 0) {
            crd->accesskeyid = json_object_to_json_string(val);
        } else if (strcmp(key, "SecretAccessKey") == 0) {
            crd->secretaccesskey = json_object_to_json_string(val);
        } else if (strcmp(key, "Token") == 0) {
            crd->token = json_object_to_json_string(val);
        }
    }
}

int main(int argc, char ** argv)
{
    if (argc < 2) {
        fprintf(stderr, "no filename given\n");
        return 1;
    }

    char *content = file_get_contents(argv[1]);
    //printf("%s", content);


    struct Credential crd;
    parse_credential(content, &crd);

    printf("%s\n", crd.accesskeyid);
    printf("%s\n", crd.secretaccesskey);
    printf("%s\n", crd.token);

    free_credential(&crd);
    free(content);

    return 0;
}
