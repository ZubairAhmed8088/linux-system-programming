# Linux System Programming (System Calls)

This repository contains simple and easy-to-understand C programs that
demonstrate commonly used Linux system calls.

Each program:
- Focuses on one system call
- Uses clear comments
- Ends with SHORT NOTES for quick revision

---

## 📂 Project Structure

### file_operations/
- open_example.c      → open()
- write_example.c     → write()
- read_example.c      → read()
- close_example.c     → close()
- readlink_example.c  → readlink()

### process_management/
- fork_example.c      → fork()
- exec_example.c      → exec()

### ipc_sockets/
- socket_example.c       → socket()
- socketpair_example.c   → socketpair()
- send_example.c         → send()
- recv_example.c         → recv()

### revision/
- all_in_one_revision.c  → combined revision program

---

## ▶️ How to Compile and Run

Use `gcc` to compile any file:

```bash
gcc filename.c
./a.out

