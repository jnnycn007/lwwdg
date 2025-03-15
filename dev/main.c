#include <stdio.h>
#include <windows.h>
#include "lwwdg/lwwdg.h"

extern void example_win32(void);
extern int test_run(void);

int
main(void) {
#if WORKFLOW_TEST
    return test_run();
#else /* WORKFLOW_TEST */
    example_win32();
    return 0;
#endif /* WORKFLOW_TEST */
}
