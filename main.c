#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG 1

#if defined(DEBUG)
#define debug printf
#else
#define debug
#endif

int main(int argc, char* argv[])
{
    char command[1024];
    char *ptr;
    unsigned char reg = 0x00;
    unsigned char data = 0x00;

    if(argc != 2)
    {
        printf("usage: ./app <command string>\n");
        printf("eg   : ./app \"i2c read 0x45\"\n");
        printf("eg   : ./app \"i2c write 0x45 0x33\"\n\n");
        return -1;
    }

    debug("sizeof(argv[1]) = %lu\n", strlen(argv[1]));
    debug("argv[1] = %s\n", argv[1]);

    memset(command, 0, 1024);
    memcpy(command, argv[1], strlen(argv[1]));
    debug("command = %s\n", command);

    ptr = strtok(command, " ");
    if(ptr == NULL)
    {
        printf("err: ptr == NULL, line = %d\n\n", __LINE__);
        return -1;
    }
    debug("cmd[0] = %s\n", ptr);

    if(0 == strcmp(ptr, "i2c"))
    {
        ptr = strtok(NULL, " ");
        if(ptr == NULL)
        {
            printf("err: ptr == NULL, line = %d\n\n", __LINE__);
            return -1;
        }
        debug("cmd[1] = %s\n", ptr);

        if(0 == strcmp(ptr, "read"))
        {
            ptr = strtok(NULL, " ");
            if(ptr == NULL)
            {
                printf("err: ptr == NULL, line = %d\n\n", __LINE__);
                return -1;
            }
            reg = (unsigned char)strtoll(ptr, NULL, 0);
            debug("cmd[2] = %s\n", ptr);

            printf("execute i2c read command\n");
            printf("reg    = 0x%x(h), %u(d)\n", reg, reg);
        }
        else if(0 == strcmp(ptr, "write"))
        {
            ptr = strtok(NULL, " ");
            if(ptr == NULL)
            {
                printf("err: ptr == NULL, line = %d\n\n", __LINE__);
                return -1;
            }
            reg = (unsigned char)strtoll(ptr, NULL, 0);
            debug("cmd[2] = %s\n", ptr);

            ptr = strtok(NULL, " ");
            if(ptr == NULL)
            {
                printf("err: ptr == NULL, line = %d\n\n", __LINE__);
                return -1;
            }

            data = (unsigned char)strtoll(ptr, NULL, 0);
            debug("cmd[3] = %s\n", ptr);

            printf("execute i2c write command\n");
            printf("reg    = 0x%x(h), %u(d)\n", reg, reg);
            printf("data   = 0x%x(h), %u(d)\n", data, data);
        }
        else
        {
            printf("err: command not support, line = %d\n\n", __LINE__);
            return -1;
        }
    }
    else
    {
        printf("err: command not support, line = %d\n\n", __LINE__);
        return -1;
    }

    printf("\n");
    return 0;
}
