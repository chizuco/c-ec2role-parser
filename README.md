# c-credential-parser

Parser for security credentials of IAM for EC2 Role

# DESCRIPTIONS

This program parses a result of EC2 security credential like below:
```
$ curl -s http://169.254.169.254/latest/meta-data/iam/security-credentials/tmprole
{
  "Code" : "Success",
  "LastUpdated" : "2014-11-10T01:49:08Z",
  "Type" : "AWS-HMAC",
  "AccessKeyId" : "ASIAJ4SU5Q7BFOOBARBUZ",
  "SecretAccessKey" : "X50UNUqMA3FxZO7RKTYu+7QUrF/JzSsbDQ36TN0N",
  "Token" : "BQoDYXdzEDsa4AP3XvDVPdt4Clu8vwTBYABY2qw+VGlvd1SCtFjYguXSNHVY1TEBuMMgvKBu7fT/WeRfGL4BqD3EhNVMecWHpNu7zkIPSB2G3HyZzVkt0Fe+U+k0oRrLTTrmSygUsyK0p9k1da2dhhqxvNS2nZxfRavmdWGT0aspPkM6FmBT/BvRPL4Zp26Xum7NUzSShAhBQUBP5vvDKdF5chcLPYfOwb0H2KVZ3lmoDCl07v3PQmvA0iXYVxTPr0x56+sQTzQNcqVHnsVa5dRCsrr2VuYE3+kjOsrzHRB7OJTjmqQciW0IVagM0eZGBhsi3LgSpNuea7QYeIs5/JfwS5Gus2VPXnllzDEeJhdQa/6aaGSuOnq0WGwq7IfVazGi5oalTy0E0REQk0whcnNdKhyMQXpV62V+teivyNa11YGbTtc6GoNMLWxQR1uNpO/bqwMrZPPIzv6+//picZa+pBKTCe+gwOADxO34moZFICMwDoPfbmtRMObyrg6AXMO6ETtf0xK2DHwodKuzkjb+AUykXguHKNxOeYLEHGF0zAq0QbbK4sYpn+GADgAjx2FZ6m2WqJrTkm34+i6XJP/RCarRBH9xD/rgP1amw2LHYwSCsXSomTZ16OTwfZDojKz/nC/SXCgVSuEgr7OAowU=",
  "Expiration" : "2014-11-10T08:05:27Z"
}
```

# Usage

# LISCENCE

GPL v3
