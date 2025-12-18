# Linux System Programming (System Calls)

This repository contains clear, well-documented C programs that demonstrate
commonly used Linux system calls.

Each program follows a consistent and structured format, including:
- Definition
- Syntax and syntax explanation
- Key points
- Step-by-step execution flow
- Expected output
- SHORT NOTES for quick revision

The focus of this repository is on clarity, correctness, and practical usage
of Linux system calls through simple, readable examples.

---

## 📂 Project Structure

### file_operations/
Programs related to Linux file handling system calls.

- open_example.c  
  → open()

- write_example.c  
  → write()

- read_example.c  
  → read()

- close_example.c  
  → close()

- readlink_example.c  
  → readlink()

---

### process_management/
Programs related to Linux process management.

- fork_example.c  
  → fork()

- exec_example.c  
  → exec()

---

### ipc_sockets/
Programs demonstrating Inter-Process Communication (IPC) using sockets.

- socket_example.c  
  → socket()

- socketpair_example.c  
  → socketpair()

- send_example.c  
  → send()

- recv_example.c  
  → recv()

---

### combined_flow/
A complete program that combines multiple Linux system calls into a single,
cohesive execution flow.

- combined_syscalls.c

This program demonstrates:
- File operations:  
  open(), write(), read(), close()
- Filesystem interaction:  
  readlink()
- Inter-process communication:  
  socketpair(), send(), recv()
- Process management:  
  fork(), exec()

It provides an end-to-end view of how multiple Linux system calls work together
within a single program.

---

## ▶️ How to Compile and Run

Use `gcc` to compile any program:

```bash
gcc filename.c
./a.out

