#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

void *__dso_handle = 0;

int main()
{
    try {
        printf("Throwing exception, tid: %d\n", gettid());
        throw int(9999);
    } catch (int e) {
        printf("Caught exception: %d\n", e);
    } catch (...) {
        printf("Caught unknown exception\n");
    }
    printf("Exiting main\n");
    return 0;
}
