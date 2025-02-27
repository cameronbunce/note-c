[![Coverage Status](https://coveralls.io/repos/github/blues/note-c/badge.svg?branch=master)](https://coveralls.io/github/blues/note-c?branch=master)

# note-c

The note-c C library for communicating with the
[Blues Wireless][blues] Notecard via serial or I²C.

This library allows you to control a Notecard by writing a C
or C++ program. Your program may programmatically configure Notecard and send
Notes to [Notehub.io][notehub].

This library is used by the [note-arduino library][note-arduino], which includes
it as a git subtree.

## Documentation

The documentation for this library can be found [here](https://blues.github.io/note-c/html/index.html).

## CMake

The CMake build system is primarily here for testing note-c on a development
machine. You can use it to generate a static or shared note-c library, but
embedded users will typically just compile all the .c source files into their
firmware image. For more on testing, see test/README.md.

### Options

- BUILD_TESTS: Build the tests. See the tests directory. Default: ON.
- BUILD_SHARED_LIBS: Build the note-c library as shared instead of static. This
reduces the total size of the compiled tests. Default: ON.

## Contributing

We love issues, fixes, and pull requests from everyone. By participating in this
project, you agree to abide by the Blues Inc [code of conduct].

For details on contributions we accept and the process for contributing, see our
[contribution guide](CONTRIBUTING.md).

## More Information

For additional Notecard SDKs and Libraries, see:

- [note-arduino][note-arduino] for Arduino support
- [note-python][note-python] for Python
- [note-go][note-go] for Go

## To learn more about Blues Wireless, the Notecard and Notehub, see:

- [blues.com](https://blues.io)
- [notehub.io][notehub]
- [wireless.dev](https://wireless.dev)

## License

Copyright (c) 2019 Blues Inc. Released under the MIT license. See
[LICENSE](LICENSE) for details.

[blues]: https://blues.com
[notehub]: https://notehub.io
[note-arduino]: https://github.com/blues/note-arduino
[note-go]: https://github.com/blues/note-go
[note-python]: https://github.com/blues/note-python
[code of conduct]: https://blues.github.io/opensource/code-of-conduct
