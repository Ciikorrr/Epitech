# MyGKrellm

### Command line arguments

- `--display` to specify the display to use

  Available options: `ncurses`, `sfml`, `imgui`, `debug`

  Default: `ncurses` or `imgui` if `IMGUI_BACKEND` is set

- `--modules` to specify the modules to enable by default

  Available options: `host`, `os`, `datetime`, `cpu`, `memory`, `battery`

  Default: all modules enabled

### ImGUI backend
- Dependencies: `glfw-devel` (Fedora)
- Compile with `IMGUI_BACKEND=1 make`
- Run with `./MyGKrellm`
