
# Clio

**Clio** is a simple, lightweight, and thread-safe header-only C++ logging library.
🚧 **Work In Progress**

## Features

- **Header-only** — No builds or dependencies are necessary.
- **Thread-safe** — Safe for concurrent logging in multi-threaded environments.
- **Configurable verbosity** — Fine-grained control over log levels.
- **Customizable output** — Redirect logs to files, streams, or custom sinks (Coming soon).

---

## Quick Start

### Installation

1. Add the `Clio` repository into your project via `git submodule add https://github.com/henryisaway/Clio.git [destination directory]` (recommended).
2. Include the main header:

```cpp
#include "Clio/clio.hpp"
````

---

### Basic Usage

```cpp
#include "Clio/clio.hpp"

int main() {

    Clio::Logger.get().setSeverityThreshold(Clio::Severity::INFO);

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
| `trace` | Fine-grained tracking of every operation being executed          |
| `debug` | Useful information for when debugging your program               |
| `info`  | Informational messages                                           |
| `warn`  | Warnings about potential issues                                  |
| `error` | Errors that occurred but do not necessarily stop the application |
| `fatal` | Critical errors; application may not continue safely             |

---

## Custom Output

Planned: Clio will support pluggable sinks for writing logs to files, streams, or network sockets.

---

## Requirements

* C++17 or later
* Standard library

---

## License

**MIT License** — Clio is free and open-source software. See [LICENSE](https://github.com/henryisaway/Clio/blob/main/LICENSE) for full details.

---

## Contributing

Issues and pull requests are welcome! If Clio helps you or your project, let me know—I'd love to see it in action.

---

## About the Name

In Greek mythology, **Clio** is the muse of history and heroic deeds. As a nod to her character, this project was named Clio for their shared duty of registering the history of their world.

---

## Author

Developed by [henryisaway](https://github.com/henryisaway)
