struct Credential
{
    const char *accesskeyid;
    const char *token;
    const char *secretaccesskey;
};

char *file_get_contents(const char *filename);
void free_credential(struct Credential *crd);
int parse_credential(const char *json_string, struct Credential *crd);
