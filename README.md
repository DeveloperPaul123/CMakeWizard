# CMakeWizard #

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/c2aa25642bd1415893c8181825bd692b)](https://www.codacy.com/app/developerpaul123/CMakeWizard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=DeveloperPaul123/CMakeWizard&amp;utm_campaign=Badge_Grade)

## Introduction ##
CMakeWizard is a simple to use setup tool for CMake based projects similar to a `New Project` wizard that you would find in a full featured IDE. I found myself getting tired of writing a `CMakeLists.txt` every time I wanted to setup a new repository. 

So I thought: "Surely, there must be something out there that can do this for me." As it turns out, there isn't really an all in one tool that could do what I wanted it to do. So I decided to make my own tool. 

The goal of this program is to simplify project setup for C++ projects that use CMake an make it super easy to do. 

## Features ##
* Supports various project types:
    * Console applications
    * Qt based Desktop GUI applications
* Auto configures finding of various external libraries.
* Easily add library sub-projects that can be re-used.
* Move existing CMake builds.
    * This allows you to move an existing build from one directory to another without breaking the build. This is done simply by configuring the `CMakeCache` correctly. 
* More to come!

## Contributing ##
Contributing is welcome and encouraged! 

