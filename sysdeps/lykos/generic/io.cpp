#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <bits/ensure.h>
#include <mlibc/debug.hpp>
#include <mlibc/all-sysdeps.hpp>
#include <lykos/syscall.h>

namespace mlibc
{
    int sys_openat(int dirfd, const char *path, int flags, mode_t mode, int *fd)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_openat" << frg::endlog;
        return -1;
    }

    int sys_open(const char *path, int flags, mode_t mode, int *fd)
    {
        int ret = syscall3(SYSCALL_OPEN, (uint64_t)path, (uint64_t)flags, (uint64_t)mode);
        *fd = ret;

        return 0;
    }

    int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read)
    {
        int ret = syscall3(SYSCALL_READ, (uint64_t)fd, (uint64_t)buf, (uint64_t)count);
        *bytes_read = ret;

        return 0;
    }

    int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written)
    {
        int ret = syscall3(SYSCALL_WRITE, (uint64_t)fd, (uint64_t)buf, (uint64_t)count);
        *bytes_written = ret;

        return 0;
    }

    int sys_seek(int fd, off_t offset, int whence, off_t *new_offset)
    {
        *new_offset = syscall3(SYSCALL_SEEK, fd, offset, whence);
        return 0;
    }

    int sys_close(int fd)
    {
        return syscall1(SYSCALL_CLOSE, (uint64_t)fd);
    }
}
