# Linux Mandatory Access Control

The Linux system has two notable mandatory access control mechanisms [SELinux][1] and [AppArmor][2]. Imagine that we have the following scenario:

1. Program X is installed at /usr/local/bin/px
2. Only UserX is allowed to execute Program X
3. Program X will retrieve the source code of Program Y from the Internet and build Program Y under /var/X/
4. Program X will install Program Y under /var/Y/
5. Program X will fork a child process to execute Program Y
6. Program Y is only allowed to read/write files under /var/Y/
7. Program Y is not allowed to create or accept network connections.

Use either SELinux or AppArmor to implement least privilege security polciy for the above scenario. In other words, your policy should minimize unnecessary accesses that could be performed by Program X or Program Y.

For simplicity, you can assume that Program X and Program Y are C/C++ programs that will be compiled into ELF executables (and possibly with a bunch of .so shared libraries).

To make the grading process more manageable, please work on your policy from a fresh installed Linux, so that the TA can apply your SELinux policy or AppArmor profile on our testbed for verification.

[1]: https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/index
[2]: https://wiki.ubuntu.com/AppArmor

# Usage

* set up environment
```bash=
sudo sh environment.sh
sudo sh StartApparmor.sh
```

* install
```bash=
make
sudo sh install.sh
```

* launch ProgramX
```bash=
sudo ./server
```

```bash=
./client 127.0.0.1
```
