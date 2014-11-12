/**
 * parse json_string as store data into struct Credential
 */
#include "ec2role_parser.h"

void free_credential(struct Credential *crd)
{
    free((void *)crd->accesskeyid);
    free((void *)crd->token);
    free((void *)crd->secretaccesskey);

    crd->accesskeyid = NULL;
    crd->token = NULL;
    crd->secretaccesskey = NULL;
}

int parse_credential_json(const char *json_string, struct Credential *crd)
{
    struct json_object *obj = json_tokener_parse(json_string);
    if (is_error(obj)) {
        return -1;
    }

    struct json_object *val_id = NULL;
    if (!json_object_object_get_ex(obj, "AccessKeyId", &val_id)) {
        return -1;
    }

    struct json_object *val_secret = NULL;
    if (!json_object_object_get_ex(obj, "SecretAccessKey", &val_secret)) {
        return -1;
    }

    struct json_object *val_token = NULL;
    if (!json_object_object_get_ex(obj, "Token", &val_token)) {
        return -1;
    }

    crd->accesskeyid = json_object_get_string(val_id);
    crd->secretaccesskey = json_object_get_string(val_secret);
    crd->token = json_object_get_string(val_token);

    return 0;
}
