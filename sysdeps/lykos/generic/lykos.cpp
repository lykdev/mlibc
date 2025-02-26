#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <bits/ensure.h>
#include <mlibc/debug.hpp>
#include <mlibc/all-sysdeps.hpp>
#include <lykos/syscall.h>

namespace mlibc {

    void sys_libc_log(const char *message)
    {
        syscall2(SYSCALL_DEBUG_LOG, (uint64_t) strlen(message), (uint64_t) message);
    }

    [[noreturn]] void sys_libc_panic()
    {
        syscall1(SYSCALL_DEBUG_LOG, 42);
    }

    [[noreturn]] void sys_exit(int status)
    {
        syscall1(SYSCALL_DEBUG_LOG, (uint64_t)status);
    }

    int sys_tcb_set(void *pointer)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_tcb_set" << frg::endlog;
        return -1;
    }

    int sys_futex_wait(int *pointer [[maybe_unused]], int expected [[maybe_unused]], const struct timespec *time [[maybe_unused]]) {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_futex_wait called" << frg::endlog;
        return -1;
    }

    int sys_futex_wake(int *pointer [[maybe_unused]]) {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_futex_wake called" << frg::endlog;
        return -1;
    }

    int sys_anon_allocate(size_t size, void **pointer)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_anon_allocate" << frg::endlog;
        return -1;
    }

    int sys_anon_free(void *pointer, size_t size)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_anon_free" << frg::endlog;
        return -1;
    }

    int sys_openat(int dirfd, const char *path, int flags, mode_t mode, int *fd)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_openat" << frg::endlog;
        return -1;
    }

    int sys_open(const char *path, int flags, mode_t mode, int *fd)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_open" << frg::endlog;
        return -1;
    }

    int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_read" << frg::endlog;
        return -1;
    }

    int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_read" << frg::endlog;
        return -1;
    }

    int sys_seek(int fd, off_t offset, int whence, off_t *new_offset)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_seek" << frg::endlog;
        return -1;
    }

    int sys_close(int fd)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_close" << frg::endlog;
        return -1;
    }

    int sys_stat(fsfd_target fsfdt, int fd, const char *path, int flags, struct stat *statbuf)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED" << frg::endlog;
        return -1;
    }

    // mlibc assumes that anonymous memory returned by sys_vm_map() is zeroed by the kernel / whatever is behind the sysdeps
    int sys_vm_map(void *hint [[maybe_unused]], size_t size [[maybe_unused]], int prot [[maybe_unused]], int flags [[maybe_unused]], int fd [[maybe_unused]], off_t offset [[maybe_unused]], void **window [[maybe_unused]])
    {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_vm_map called" << frg::endlog;
        return -1;
    }

    int sys_vm_unmap(void *pointer [[maybe_unused]], size_t size [[maybe_unused]])
    {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_vm_unmap called" << frg::endlog;
        return -1;
    }

    int sys_vm_protect(void *pointer [[maybe_unused]], size_t size [[maybe_unused]], int prot [[maybe_unused]])
    {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_vm_protect called" << frg::endlog;
        return -1;
    }

    int sys_clock_getres(int clock, time_t *secs, long *nanos)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED" << frg::endlog;
        return -1;
    }

    int sys_clock_get(int clock, time_t *secs, long *nanos)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED" << frg::endlog;
        return -1;
    }

    int sys_isatty(int fd [[maybe_unused]])
    {
        // TODO: Implement
        return ENOTTY;
    }

    int sys_uname(struct utsname *buf)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED" << frg::endlog;
        return -1;
    }

    int sys_getcwd(char *buffer, size_t size)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED" << frg::endlog;
        return -1;
    }

}