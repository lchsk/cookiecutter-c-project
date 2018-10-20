# Cookiecutter template for C projects

Generate a new C project with a quick cookiecutter command:

```
$ cookiecutter cookiecutter-c-project
```

## Features

- Generates a new C project built with CMake
- It can optionally include installation commands
- It can optionally generate configuration for building `DEB` and `RPM` packages with CPack
- It generates a `man` page
- It can optionally add CMake configuration for Glib and Curses libraries

## Variables

| Variable       | Description         |
|----------------|---------------------|
| `project_name` | Name of the project |
| `project_short_description` | Short description of the project |
| `license` | License e.g. `GPLv3` |
| `author_name` | Author's name |
| `author_email` | Author's email |
| `c_standard` | C language standard: `99`, `90`, `11` |
| `add_installation` | If `y` then installation command (`make install`) will be generated |
| `use_cpack` | If `y` then commands to generate `DEB` and `RPM` packages will be added |
| `add_glib` | If `y` then it will be built with Glib library |
| `add_curses` | If `y` then it will be built with Curses library |


