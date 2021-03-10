# alia-html-starter

[![Deployment](https://github.com/alialib/alia-html-starter/actions/workflows/deployment.yml/badge.svg)](https://github.com/alialib/alia-html-starter/actions/workflows/deployment.yml)

This is a starter template for using alia/HTML.

You can see it deployed here:

https://alialib.github.io/alia-html-starter

## Usage

These instructions assume you're running Linux (and will work inside the
Windows Subsystem for Linux).

1. Ensure sure that you have [CMake](https://cmake.org/) (3.14 or higher) and
   [Emscripten](https://emscripten.org/docs/getting_started/downloads.html)
   (1.39.18 or higher).

1. Use this repository as a template to create your own instance of it. (Just
   press the big green button at the top.)

1. Clone your repository locally.

1. Build it. (Be sure to activate Emscripten for your shell before doing this.)

   ```
   mkdir build
   cd build
   emcmake cmake ..
   make -j
   ```

   Another option is to use VS Code with the CMake Tools extension to
   automatically handle this process. Just select the Emscripten kit and it
   should all work.

1. To view your app, you'll need to run a web server to serve the files within
   the `build/deploy` directory. A Python 2.x script is included that will do
   this for you:

   ```
   cd build/deploy
   python2 ../../scripts/run-web-server.py
   ```

   With that running, you can navigate to http://localhost:8020/ to see your
   app.

1. Edit `src/app.cpp` and try some things. You can find lots of ready-to-use
   code snippets within [the HTML demos](https://html.alia.dev/) and [the
   docs](https://alia.dev/).

   Just rebuild and do a hard refresh (Ctrl-F5) to see your changes.

   Also feel free to edit `index.html` and `style.css` right from the `src/`
   directory.

The repository is configured to automatically deploy to the `gh-pages` branch,
so if you enable GitHub Pages for your repository, you can also see your
creation live on the web!
