#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

int main(){
    char string[1024] = "miraelim", nonce[1024]="3";
    char key[1024];
    char hmac1[1024],hmac2[1024], nhmac1[1024],nhmac2[1024];
    unsigned int *len1, *len2, *nlen1, *nlen2;
    int result1;
    FILE *keyobj;
    keyobj = fopen("keyobject.txt","r");
    fscanf(keyobj, "%s", key);
    printf("%s\n",key);
    HMAC(EVP_sha256(),key,strlen(key), nonce, strlen(nonce),hmac1, len1);
    printf("%s\n",hmac1);
    HMAC(EVP_sha256(),key,strlen(key), nonce, strlen(nonce),hmac2, len2);
    printf("%s\n",hmac2);
    result1= strcmp(hmac1, hmac2);
    printf("%d\n",result1);
    return 0;
}
