## ldf

    report filesystem space info of devices

## installation

    $ make
    # make install

## un-installation

    $ make clean
    # make uninstall

## installation with cmake

    $ cmake -B build
    $ cd build
    $ make
    # make install

## un-installation with cmake

    $ cd build
    # make uninstall
    $ cd ..
    $ rm -rf build

## usage

    read the --help statement

## files
    
    when running "$ make" compiles the program and the binary is placed in the repo's main directory and build files in ./build 
    when running "# make install" the binary file is copied to /usr/bin/ldf , and the man page to /usr/share/man/man1/ldf.1

    when running "$ make clean" the ./build is removed. And the binary is removed from the repo's directory but not from /usr/bin/ldf
    when running "# make uninstall" the binary file is removed from /usr/bin/ldf as well as /usr/share/man/man1/ldf.1
