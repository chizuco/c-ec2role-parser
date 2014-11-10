#include <json-c/json.h>

struct Credential
{
    const char *accesskeyid;
    const char *token;
    const char *secretaccesskey;
};

void free_credential(struct Credential *crd);
int parse_credential(const char *json_string, struct Credential *crd);
