* [Py2Ipynb](#py2ipynb)
   * [Theory](#theory)
   * [Install](#install)
      * [CMake](#cmake)
      * [Manually](#manually)
   * [TODO](#todo)

# Py2Ipynb

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
gcc -o py2ipynb src/py2ipynb.c ../lib/cJSON.c -lm -I../lib
```

## TODO

* In the cernent version, the code in *\*.py* can only be put in the first cell. In a new version, I will add some paramater to auto-split a *\*.py* file into different cells. Or show the *\*.py* file line by line and split the cells at user's will.

* Several types to split *\*.py* may be added.

* The **Python** version is fixed with 3.7.6, which should be upgrade to being able to auto-detect the **Python** version, and ask for choose if detected 2 or more version.

* The id of cell is 12345678 for test, the way how *\*.ipynb* makes id needs to learn.

* There is an unknown bug that when open the converted file in *jupyter notebook*, it seems that the *name* should be defined in the **language_info** key, but I do define the *name*. Having run the new *\*.ipynb* several times, *jupyter notebook* doesn't alert any more, maybe there is something to do with the *id*?

* The helping message and fault-tolerant mechanism should be added.

* Converting more files with one pattern command needed.

