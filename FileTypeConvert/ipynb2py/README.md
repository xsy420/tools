* [Ipynb2Py](#ipynb2py)
   * [Theory](#theory)
   * [Install](#install)
      * [CMake](#cmake)
      * [Manually](#manually)
   * [TODO](#todo)

# Ipynb2Py

## Theory

As long as you take a look at any *\*.ipynb* file with *vi* or *vim*, it will be easy to find out that the *\*.ipynb* file is actually a json file. And the **Python** code is in the "**source**" key.

So the conversion problem suddenly becomes to the problem how **C Language** parses json.

Then parse the **source** key into a *\*.py* file or create a new json into *\*.ipynb* with **Python** code added.

At the first time, I found *json.h*, which seems to be unavailable to parse the list in json. So I turned to *cJSON.h*.

## Install

### CMake

```bash
cmake -B bin && cd bin && make
```

### Manually

```bash
gcc -o ipynb2py src/ipynb2py.c ../lib/cJSON.c -lm -I../lib
```

## TODO

* When converting exactly with **source**, some outputs will not be shown when executing. So the special output in ipynb (output an object without *print()* function) should be detected, and added with *print()* when converting.

* The helping message and fault-tolerant mechanism should be added.

* Converting more files with one pattern command needed.

