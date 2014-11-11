#include <json-c/json.h>
/**
 * struct to store AWS STS Credential
 *
 * see http://docs.aws.amazon.com/STS/latest/UsingSTS/Welcome.html
 */
struct Credential
{
    const char *accesskeyid;
    const char *token;
    const char *secretaccesskey;
};

void free_credential(struct Credential *crd);

/**
 * parse json_string and set credential structure
 * @return -1:error,  0:success
 */
int parse_credential_json(const char *json_string, struct Credential *crd);
