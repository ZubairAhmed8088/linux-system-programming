# Linux System Programming (System Calls)

This repository contains **clear, well-documented C programs**
demonstrating commonly used **Linux system calls**.

Each program is written in a **structured learning format** with:
- Definition
- Syntax & syntax explanation
- Key points
- Step-by-step execution flow
- Expected output
- SHORT NOTES for quick revision

This makes the repository suitable for **learning, revision, and explanation**.

---

## 📂 Project Structure

### file_operations/
Programs related to Linux file handling system calls.

- `open_example.c`      → open()
- `write_example.c`     → write()
- `read_example.c`      → read()
- `close_example.c`     → close()
- `readlink_example.c`  → readlink()

---

### process_management/
Programs related to Linux process management.

- `fork_example.c`      → fork()
- `exec_example.c`      → exec()

---

### ipc_sockets/
Programs demonstrating Inter-Process Communication (IPC) using sockets.

- `socket_example.c`       → socket()
- `socketpair_example.c`   → socketpair()
- `send_example.c`         → send()
- `recv_example.c`         → recv()

---

### revision/
Final revision program combining **all major system calls** in one flow.

- `all_in_one_revision.c`  
  → open(), write(), read(), close()  
  → readlink()  
  → socketpair()  
  → fork(), send(), recv()  
  → exec()

This file is intended as a **complete end-to-end revision example**.

---

## ▶️ How to Compile and Run

Use `gcc` to compile any program:

```bash
gcc filename.c
./a.out

