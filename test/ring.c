#include <stdlib.h>
#include "actor.h"

atom ring(int n, actor *p) {
    if (n == 0) {
        send(p, OK);
        return OK;
    }
    actor *p = spawn(ring, n - 1, pid);
    send(p, OK);
    atom msg = recv();
    if (msg == OK) {
        return OK;
    }
    return UNHANDLED;
}

atom root() {
    atom msg = recv();
    printf("recv msg=%s", show(msg));
}

void start(int n) {
    actor *p = swpan(root, 0);
}

int main(int argc, char **argv) {
    int num = 5;
    if (argc > 1) {
        num = atoi(argv[1]);
    }
    start(num);
    while (1) {
        sleep(1);
    }
    return 0;
}
