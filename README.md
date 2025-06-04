
# Clio

**Clio** is a simple, lightweight, and thread-safe header-only C++ logging library.  
🚧 **Work In Progress**

## Features

- ✅ **Header-only** — Just include and go. No builds, no dependencies.
- ✅ **Thread-safe** — Safe for concurrent logging in multi-threaded environments.
- ✅ **Configurable verbosity** — Fine-grained control over log levels.
- ✅ **Lightweight** — Minimal footprint; designed for high-performance applications.
- ✅ **Customizable output** — Redirect logs to files, streams, or custom sinks (Coming soon).

---

## Quick Start

### Installation

1. Copy the `Clio/` directory into your project.
2. Include the main header:

```cpp
#include "Clio/clio.hpp"
````

That’s it. No builds, no external dependencies.

---

### Basic Usage

```cpp
#include "clio/clio.hpp"

int main() {
    CLIO_INFO("You can log simple messages like this!");

    const int x = 5;
    // If you need to log the value of a variable, you can easily do it!
    CLIO_WARN("Value of x is ", x, " and I don't like it!");
    
    const bool error = true;
    // You can log as many variables as you like:
    CLIO_ERROR("Now x is ", x, " and error is ", error, ", this couldn't possibly get any worse!");

    //Different log severities are available to use!
    CLIO_FATAL("This got out of hand. Exiting the program, now!");
    
    return 0;
}
```

---

### Thread Safety

Clio uses std::mutex internally to ensure all log operations are safe across multiple threads. While this guarantees safety, it may introduce minor contention in heavily parallelized environments.

---

## Log Levels

| Level   | Description                                                      |
| ------- | ---------------------------------------------------------------- |
| `info`  | Informational messages                                           |
| `warn`  | Warnings about potential issues                                  |
| `error` | Errors that occurred but do not necessarily stop the application |
| `fatal` | Critical errors; application may not continue safely             |

---

## Custom Output

Planned: Clio will support pluggable sinks for writing logs to files, streams, or network sockets.

---

## Why Clio?

* ✨ **Minimalist** — No fluff, just logging.
* 🏎️ **Fast** — Zero-cost abstractions wherever possible.
* 🛠️ **Portable** — Works anywhere C++17 is available.
* 🧵 **Thread-safe** — No more log mangling in multi-threaded code.

---

## Requirements

* C++17 or later
* Standard library (no third-party dependencies)

---

## License

**MIT License** — Clio is free and open-source software. See [LICENSE](https://github.com/henryisaway/Clio/blob/main/LICENSE) for full details.

---

## Contributing

Issues and pull requests are welcome! If Clio helps you or your project, let me know—I'd love to see it in action.

---

## About the Name

In Greek mythology, **Clio** is the muse of history and heroic deeds.

---

## Author

Developed by [henryisaway](https://github.com/henryisaway)