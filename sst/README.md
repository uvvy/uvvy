Structured Streams Transport
============================

SST is an experimental transport protocol designed to address the needs
of modern applications that need to juggle many asynchronous communication
activities in parallel, such as downloading different parts of a web page
simultaneously and playing multiple audio and video streams at once.

Project home page: http://pdos.csail.mit.edu/uia/sst/

Using SST
=========

...modes of use...

...event loop integration:
(a) if your app uses Qt...
(b) if your app uses glib...  Qt 4.2 contains built-in support
    for integration with glib's event loop.
    Make sure Qt was compiled and installed with
    glib support (the -glib option on the configure line).
    Qt will then by default use glib's main event loop instead of its own.
(c) if neither of the above apply, implement a few callback functions...


Directory Structure
===================

inc         Public C/C++ header files for SST libraries
lib         Core SST protocol stack implementation library (libsst)
c           API wrapper/remote access library for C programs (libsst_c)
doc         Documentation for the SST protocol stack and API wrapper
rpcgen      Version of Sun rpcgen modified to produce Qt-style XDR stubs
shell       Simple SST-based remote shell application
test        Various small test, analysis, and demo programs


License
=======

The SST prototype implemenation relies on the Qt 4 toolkit from Trolltech, now
part of Nokia.  Qt versions 4.0 through 4.4 were released under the GNU General
Public License, version 2, which meant that SST had to be released under this
license as well since SST must be linked with Qt.

Nokia announced in January 2009 that starting with Qt version 4.5, the open
source release of Qt would be made available under the more liberal GNU Lesser
General Public License (LGPL), which allows proprietery programs to be linked
with LGPL-licensed libraries.  We have already updated SST's licensing terms to
match (see COPYING-LGPL for details).  Note however that the more liberal terms
will only be available when using SST with Qt 4.5 or later once Qt 4.5 becomes
available.  Please feel free to contact us if you would like to use Qt but have
concerns about licensing issues.
