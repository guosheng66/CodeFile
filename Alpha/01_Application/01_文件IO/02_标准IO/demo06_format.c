#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[48] = {0};

    printf("printf:%d(%s)%d(%s)\n", 520, "我爱你", 1314, "一生一世");
    fprintf(stdout, "fprintf:%d(%s)%d(%s)\n", 520, "我爱你", 1314, "一生一世");
    dprintf(STDOUT_FILENO, "dprintf%d(%s)%d(%s)\n", 520, "我爱你", 1314, "一生一世");

    sprintf(buf, "%d(%s)%d(%s)\n", 520, "我爱你", 1314, "一生一世");
    printf("sprintf:%s", buf);

    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf), "%d(%s)%d(%s)\n", 520, "我爱你", 1314, "一生一世");
    printf("snprintf:%s", buf);

    return 0;
}
