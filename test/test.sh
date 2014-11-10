#!/bin/bash
cd $(dirname $0);
cd ..
diff <(./parse credential_sample.json)  test/expect.txt && echo ok

