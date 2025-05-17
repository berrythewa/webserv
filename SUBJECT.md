# Webserv

> This is when you finally understand why URLs start with HTTP

## Summary

This project is about writing your own HTTP server.  
You will be able to test it with an actual browser.  
HTTP is one of the most widely used protocols on the internet.  
Understanding its intricacies will be useful, even if you won’t be working on a website.

---

## I. Introduction

The Hypertext Transfer Protocol (HTTP) is an application protocol for distributed, collaborative, hypermedia information systems.

HTTP is the foundation of data communication for the World Wide Web.

The primary function of a web server is to:
- Store, process, and deliver web pages to clients using HTTP.
- Serve HTML documents, images, stylesheets, and scripts.

Clients (like browsers) send requests using HTTP, and servers respond with content or error messages.

HTTP also enables data submission (e.g. forms, file uploads).

---

## II. General Rules

- Your program **must not crash** or terminate unexpectedly.
- Submit a **Makefile** that compiles your source files.
- Makefile must contain rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- Compile with: `c++ -Wall -Wextra -Werror -std=c++98`
- Prefer C++ versions of functions over C versions.
- **No external or Boost libraries allowed**.

---

## III. Mandatory Part

- **Program name**: `webserv`
- **Files to turn in**: Makefile, `.cpp`, `.h/.hpp`, config files
- **Execution**: `./webserv [configuration file]`
- All functionality must be implemented in **C++98**

### Allowed System Calls (examples):

- `execve`, `dup2`, `pipe`, `fork`, `socket`, `bind`, `accept`, `listen`, `send`, `recv`
- `poll`, `select`, `epoll_create`, `epoll_ctl`, `epoll_wait`, `kqueue`, `kevent`
- `fcntl`, `read`, `write`, `close`, `open`, `access`, `stat`, `opendir`, `readdir`, `closedir`

---

### III.1 Requirements

- The server must use a configuration file or default path.
- Must remain **non-blocking at all times**.
- Use **1 poll() or equivalent** for all I/O operations.
- Must not read/write without going through poll/select/etc.
- No `errno` checking after read/write.
- FD macros like `FD_SET`, `FD_CLR` are allowed.
- Must not hang indefinitely.
- Must be compatible with standard browsers.
- **HTTP 1.1 compliant** (compare with NGINX).
- Must return correct status codes.
- Default error pages if none are configured.
- Only use `fork()` for CGI.
- Must serve static sites.
- Must support **GET**, **POST**, and **DELETE**.
- Must support file upload.
- Must handle **multiple ports**.

---

### III.2 For MacOS Only

You may use `fcntl()` with:
- `F_SETFL`
- `O_NONBLOCK`
- `FD_CLOEXEC`

Only to handle `write()` behavior on macOS.

---

### III.3 Configuration File

Inspired by NGINX.

Must support:
- Host and port definition per server block.
- `server_name` (optional).
- Default server for each host:port pair.
- Default error pages.
- Body size limit.
- Route definitions:
  - Allowed HTTP methods.
  - Redirects.
  - File/directory root.
  - Directory listing toggle.
  - Default file for directories.
  - CGI execution by file extension.
  - File upload and storage path.

**CGI Details**:
- You won’t call CGI directly, use full `PATH_INFO`.
- Handle chunked input: server must unchunk before passing to CGI.
- EOF should mark the end of CGI output if no content-length.
- Run CGI with correct working directory.
- Support at least one CGI (e.g. PHP or Python).

You must include test configuration and default files.

Test behavior using NGINX if unsure.  
Testing tools in Python, Golang, or C++ recommended.

---

## IV. Bonus Part

Optional — Only evaluated if mandatory part is complete and perfect.

Bonus ideas:
- Cookie and session support.
- Multiple CGI handling.

---

## V. Submission & Evaluation

- Submit via Git repository.
- Only repository contents will be evaluated.
- Check file names carefully.

