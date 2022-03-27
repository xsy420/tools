[TOC]

# Tools

In this dictionary, you'll find several tools written by **C Language** to convert file types. 

For this version of Algorithm, it is only supported by the conversion between python file (*\*.py*) and ipython file (*\*.ipynb*).

As we all known, there are two file types of python. Sometimes, we use *\*.ipynb*, and maybe some other day, we need to use *\*.py*. To convert in these two file types quickly can save us much time.

And for the security, I choose the **C Language** which will make a binary file after compilation.

## Theory

As long as you take a look at any *\*.ipynb* file with *vi* or *vim*, it will be easy to find out that the *\*.ipynb* file is actually a json file. And the **Python** code is in the "**source**" key.

So the conversion problem suddenly becomes to the problem how **C Language** parses json.

Then parse the **source** key into a *\*.py* file or create a new json into *\*.ipynb* with **Python** code added.

At the first time, I found *json.h*, which seems to be unavailable to parse the list in json. So I turned to *cJSON.h*.

## Install

### **·** Environment

Linux Operation System

I used some commands in Linux, such as **sed**, so it's now available on Linux, or maybe MacOS (I haven't a virtual machine of MacOS yet, so I'm not sure)

### **·** Commands

These tools are easy to install, you just need to install a **C Compiler** such as gcc.

By using the **make** command, these will be installed through **Makefile**.

Or you can just compile *\*.c* files manually with the command in **Makefile**.

## Usage

./[tool name] \[Option\] \[the file path you need to convert\]

And you get a new file converted at the same path of the converting file.

## Needed to be done

The *ipynb2py* tool:

**·** When converting exactly with **source**, some outputs will not be shown when executing. So the special output in ipynb (output an object without *print()* function) should be detected, and added with *print()* when converting.

The *py2ipynb* tool:

**·** In the cernent version, the code in *\*.py* can only be put in the first cell. In a new version, I will add some paramater to auto-split a *\*.py* file into different cells. Or show the *\*.py* file line by line and split the cells at user's will.

**·** Several types to split *\*.py* may be added.

**·** The **Python** version is fixed with 3.7.6, which should be upgrade to being able to auto-detect the **Python** version, and ask for choose if detected 2 or more version.

**·** The id of cell is 12345678 for test, the way how *\*.ipynb* makes id needs to learn.

**·** There is an unknown bug that when open the converted file in *jupyter notebook*, it seems that the *name* should be defined in the **language_info** key, but I do define the *name*. Having run the new *\*.ipynb* several times, *jupyter notebook* doesn't alert any more, maybe there is something to do with the *id*?

For both two:

**·** The helping message and fault-tolerant mechanism should be added.

**·** Converting more files with one pattern command needed.

