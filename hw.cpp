#include <stdio.h>

template<typename T>
T qwe(T n);

int
main(int argc, char **argv, char **envp) {
        qwe(42);
        printf("Hello, World!\n");
        return 0;
}

