# live-datetime-cli
A small terminal clock written in C. It prints the current date and time, live. Installs to `/usr/local/bin` with `make install`, and is run with `live-datetime`.
Feel free to change the code as you'd like. MIT License applies.

## Requirements
- Linux
- `gcc` and `make`
- ANSI Escape Sequence support

## Build & run
```shell
make build
make run
```

## Install & uninstall (to /usr/local/bin)
```shell
make install
make uninstall
```

## Output format
By default, the output format is `asctime()`'s, for example:
`Fri Oct  2 19:58:00 2026`

To use the custom `DD/MM/YYYY hh:mm:ss` format, uncomment this line at the top of `live-datetime.c`:
`// #define USE_CUSTOM_TIMEDATE_FORMAT`
Example of this custom format:
`02/10/2026 19:58:00`

Keywords:
terminal clock, CLI, command line, live clock, real-time, datetime, C, Linux, lightweight, minimal, no dependencies
