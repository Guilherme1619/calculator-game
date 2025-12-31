# Setup Instructions

This project includes raylib bundled locally, so you don't need to install it separately.

## Requirements
- Make (usually pre-installed on macOS/Linux)

## Building
simply run:
make openwindow

## Running
simply run:
./openwindow

## For Other Platforms

The included raylib library (`libs/raylib/libraylib.a`) is compiled for macOS. If you're on a different platform:

1. Install raylib for your platform
2. Update the Makefile paths, OR
3. Download the appropriate raylib binary for your platform and replace `libs/raylib/libraylib.a`

## Troubleshooting

If you get "raylib.h not found" errors in your IDE:
- The code should still compile fine with `make`
- For VS Code, the `.vscode/c_cpp_properties.json` file should help IntelliSense find the header

