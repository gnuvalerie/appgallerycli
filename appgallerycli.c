#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <app_id>\n", argv[0]);
        return 1;
    }

    char cmd[512];
    snprintf(cmd, sizeof(cmd), 
        "curl -L -o '%s.apk' 'https://appgallery.cloud.huawei.com/appdl/%s'",
        argv[1], argv[1]);

    int ret = system(cmd);
    
    if (ret == 0) {
        printf("saved to %s.apk\n", argv[1]);
    } else {
        fprintf(stderr, "download failed\n");
        return 1;
    }

    return 0;
}
