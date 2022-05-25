Building on Unix/Linux/OS X
---------------------------

The configure script will customize the way the software is built and
installed into your system along with detecting the available libraries
that have been installed.  To use the default configuration just run:

    ./autogen.sh
    ./configure

For more help on how to customize the build configuration, run:

    ./configure --help

Once the configure script has run successfully, you are ready to build.
Run:

    make

This will build all of the core ActiveMQ CPP source code.  To build and
install the code into the system directories, run:

    make install

You will have to become the superuser in order to be able to install the
JNI libraries.


### OS X Lion requirements

Install brew.  It will depends on XCode being installed along with 
the command line tools.  Then use brew to install autoconf, automake,
and libtool.

    brew install autoconf automake libtool

