#ifndef _ELYSIUM__SYSCALL_H
#define _ELYSIUM__SYSCALL_H

#include <stdint.h>

#define SYSCALL_EXIT 0
#define SYSCALL_DEBUG_LOG 1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#ifndef __MLIBC_ABI_ONLY
#define DEFINE_SYSCALL(...)                     \
    uint64_t ret;                               \
    asm volatile("syscall"                      \
        : "=a" (ret)                            \
        : __VA_ARGS__                           \
        : "rcx", "r11", "memory"                \
    );                                          \
    return ret;

#ifdef __cplusplus
extern "C" {
#endif

    static uint64_t syscall0(int sc) {
        DEFINE_SYSCALL("a" (sc));
    }

    static uint64_t syscall1(int sc, uint64_t arg1) {
        DEFINE_SYSCALL("a" (sc), "D" (arg1));
    }

    static uint64_t syscall2(int sc, uint64_t arg1, uint64_t arg2) {
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2));
    }

    static uint64_t syscall3(int sc, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3));
    }

    static uint64_t syscall4(int sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
        register uint64_t arg4_reg asm("r10") = arg4;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg));
    }

    static uint64_t syscall5(int sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
        register uint64_t arg4_reg asm("r10") = arg4;
        register uint64_t arg5_reg asm("r8") = arg5;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg), "r" (arg5_reg));
    }

    static uint64_t syscall6(int sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
        register uint64_t arg4_reg asm("r10") = arg4;
        register uint64_t arg5_reg asm("r8") = arg5;
        register uint64_t arg6_reg asm("r9") = arg6;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg), "r" (arg5_reg), "r" (arg6_reg));
    }

#ifdef __cplusplus
}
#endif
#endif

#endif
