sysdep_supported_options = {
	'posix': true,
	'linux': true,
	'glibc': true,
	'bsd': true,
}

rtld_sources += files(
	'generic/filesystem.cpp',
	'generic/lemon.cpp',
)

libc_sources += files(
	'generic/entry.cpp',
	'generic/filesystem.cpp',
	'generic/lemon.cpp',
	'generic/pty.cpp',
	'generic/signals.cpp',
	'generic/sockets.cpp',
	'generic/thread_entry.S',
	'generic/thread.cpp'
)

if not no_headers
	install_headers(
		'include/abi-bits/auxv.h',
		'include/abi-bits/seek-whence.h',
		'include/abi-bits/vm-flags.h',
		'include/abi-bits/errno.h',
		'include/abi-bits/fcntl.h',
		'include/abi-bits/in.h',
		'include/abi-bits/resource.h',
		'include/abi-bits/signal.h',
		'include/abi-bits/stat.h',
		'include/abi-bits/statx.h',
		'include/abi-bits/socket.h',
		'include/abi-bits/termios.h',
		'include/abi-bits/time.h',
		'include/abi-bits/blkcnt_t.h',
		'include/abi-bits/blksize_t.h',
		'include/abi-bits/dev_t.h',
		'include/abi-bits/gid_t.h',
		'include/abi-bits/ino_t.h',
		'include/abi-bits/mode_t.h',
		'include/abi-bits/nlink_t.h',
		'include/abi-bits/pid_t.h',
		'include/abi-bits/uid_t.h',
		'include/abi-bits/access.h',
		'include/abi-bits/wait.h',
		'include/abi-bits/limits.h',
		'include/abi-bits/utsname.h',
		'include/abi-bits/ptrace.h',
		'include/abi-bits/poll.h',
		'include/abi-bits/epoll.h',
		'include/abi-bits/packet.h',
		'include/abi-bits/inotify.h',
		'include/abi-bits/clockid_t.h',
		'include/abi-bits/ipc.h',
		'include/abi-bits/shm.h',
		'include/abi-bits/mqueue.h',
		'include/abi-bits/suseconds_t.h',
		'include/abi-bits/fsfilcnt_t.h',
		'include/abi-bits/fsblkcnt_t.h',
		'include/abi-bits/socklen_t.h',
		'include/abi-bits/statfs.h',
		'include/abi-bits/statvfs.h',
		'include/abi-bits/ioctls.h',
		'include/abi-bits/xattr.h',
		'include/abi-bits/msg.h',
		'include/abi-bits/random.h',
		'include/abi-bits/rlim_t.h',
		'include/abi-bits/sigval.h',
		'include/abi-bits/sigevent.h',
		'include/abi-bits/utmpx.h',
		'include/abi-bits/utmp-defines.h',
		subdir: 'abi-bits',
		follow_symlinks: true
	)
	install_headers(
		'include/lemon/syscall.h',
		subdir: 'lemon'
	)
endif

if not headers_only
	crt = custom_target('crt0',
		build_by_default: true,
		command: c_compiler.cmd_array() + ['-c', '-o', '@OUTPUT@', '@INPUT@'],
		input: 'crt-x86_64/crt0.S',
		output: 'crt0.o',
		install: true,
		install_dir: get_option('libdir')
	)
endif

