AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}
AM_CPPFLAGS = $(gtkmm_CFLAGS) $(jack2_CFLAGS) $(kyotocabinet_CFLAGS) -std=c++11 -pthread
bin_PROGRAMS = aram
aram_SOURCES = src/main/cc/main.cc \
                                src/main/cc/util/system.cc \
                                src/main/cc/device/database.cc \
                                src/main/cc/model/application.cc \
                                src/main/cc/device/cursor.cc
aram_LDADD = $(gtkmm_LIBS) $(jack2_LIBS) $(kyotocabinet_LIBS)
aram_LDFLAGS = -pthread

## dist_noinst_SCRIPTS = autogen.sh
