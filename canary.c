#include <stdio.h>

int foo(const char *s, int n) {
        int res = 0;
        char *p, buf[20];

        sprintf(buf, "%s: %d", s, n);
        for (p = buf; *p; p++)
                res += *p;
        return res;
}

int
main(int argc, char **argv, char **envp) {
        int     n;

        n = foo(argv[1], argc);
        printf("Result: %d\n", n);
        return 0;
}
