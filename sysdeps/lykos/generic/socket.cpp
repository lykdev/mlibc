#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <sys/socket.h>

#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

#include <lykos/syscall.h>


namespace mlibc
{
    int sys_accept(int fd, int *newfd, struct sockaddr *addr_ptr, socklen_t *addr_length, int flags)
    {
		return syscall(SYSCALL_ACCEPT, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);
	}

    int sys_bind(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
    {
		return syscall(SYSCALL_BIND, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);
	}

	int sys_connect(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
    {
		return syscall2(SYSCALL_CONNECT, (uint64_t)fd, (uint64_t)&addr_ptr->sa_data[0]);
	}    
    
    int sys_listen(int fd, int backlog)
    {
		return syscall1(SYSCALL_LISTEN, (uint64_t)fd);
	}

    int sys_socket(int family, int type, int protocol, int *fd)
    {
		return syscall(SYSCALL_SOCKET, (uint64_t)family, (uint64_t)type, (uint64_t)protocol);
	}
}
