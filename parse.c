#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "parse.h"

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

int parse_credential(const char *json_string, struct Credential *crd)
{
    struct json_object *obj = json_tokener_parse(json_string);
    if (is_error(obj)) {
        return -1;
    }

    struct json_object *val_id = json_object_object_get(obj, "AccessKeyId");
    if (is_error(val_id)) {
        return -1;
    }

    struct json_object *val_secret = json_object_object_get(obj, "SecretAccessKey");
    if (is_error(val_secret)) {
        return -1;
    }

    struct json_object *val_token = json_object_object_get(obj, "Token");
    if (is_error(val_token)) {
        return -1;
    }

    crd->accesskeyid = json_object_get_string(val_id);
    crd->secretaccesskey = json_object_get_string(val_secret);
    crd->token = json_object_get_string(val_token);

    return 0;
}
