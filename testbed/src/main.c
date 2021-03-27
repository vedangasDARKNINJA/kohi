#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    KFATAL("A test message: %f", 2.5f)
    KERROR("A test message: %f", 2.5f)
    KWARN("A test message: %f", 2.5f)
    KINFO("A test message: %f", 2.5f)
    KDEBUG("A test message: %f", 2.5f)
    KTRACE("A test message: %f", 2.5f)

    KASSERT(1==0);
    return 0;
}