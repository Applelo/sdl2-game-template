# sdl2-template

> Base template to create multiplatforms games for PSP/PSVita/Mac/Windows/Linux with SDL2


This boilerplate currently supports Mac OS, the PSVita and the PSP. More platforms to come !

## Requirements

This template has been mainly develop to create multiplatforms games thanks to SDL2 and serve as a quick base.
You will need to modify the `CMakeLists.txt` file to suite your needs.

Default libs used :
- SDL2
- SDL2 Image
- SDL2 Mixer
- SDL2 TMX Lite

### IDE

To work with this template, the project need to be edit with Visual Studio Code. You will need the following extensions :

- CMake Tools by Microsoft
- C/C++ by Microsoft
- Clang-Format by xaver

### Env

The project uses additional env variables to use cmake command `emulator`, `send` and `send_vpk` specific for PSVita.

```shell
  export VITA_IP="10.0.0.26",
  export VITA3K_PATH="/Applications/Vita3K.app/Contents/MacOS/Vita3K"
```

### Platforms

#### PSVita

You need to install the [VITASDK](https://github.com/vitasdk/vdpm) to build homebrew for PlayStation Vita. The SDL libraries come with it.

Currently, to use [TMXLite](https://github.com/fallahn/tmxlite/wiki/Quick-Start), you need to build yourself the library.


#### PSP

You need to install the [PSPToolchain](https://github.com/pspdev/psptoolchain) to build homebrew for PlayStation Portable. The SDL libraries come with it.

Currently, to use [TMXLite](https://github.com/fallahn/tmxlite/wiki/Quick-Start), you need to build yourself the library.


#### Mac

You need to have a Mac (yeah obvious) with Xcode and the command lines tools installed.

Install all SDL libraries you need (see SDL2 doc). You can use also homebrew if you prefer.

If you want to use tmxlite, see [the official doc](https://github.com/fallahn/tmxlite/wiki/Quick-Start)
