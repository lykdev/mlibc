#include <lykos/syscall.h>

#include <bits/ensure.h>
#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/socket.h>

namespace mlibc
{
    int sys_accept(int fd, int *newfd, struct sockaddr *addr_ptr, socklen_t *addr_length, int flags)
    {
		int64_t ret = syscall2(SYSCALL_ACCEPT, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);

        if (ret < 0)
            return ret;
        else
            *newfd = ret;

		return 0;
	}

    int sys_bind(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
    {
		int ret = syscall2(SYSCALL_BIND, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);

        if (ret < 0)
            return ret;

		return 0;
	}

	int sys_connect(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
    {
		int ret = syscall2(SYSCALL_CONNECT, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);

        if (ret < 0)
            return ret;

		return 0;
	}    
    
    int sys_listen(int fd, int backlog)
    {
		int ret = syscall1(SYSCALL_LISTEN, (uint64_t)fd);

        if (ret < 0)
            return ret;

		return 0;
	}

    int sys_socket(int family, int type, int protocol, int *fd)
    {
		int ret = syscall3(SYSCALL_SOCKET, (uint64_t)family, (uint64_t)type, (uint64_t)protocol);

        if (ret < 0)
            return ret;
        else
		    *fd = ret;

		return 0;
	}
}
