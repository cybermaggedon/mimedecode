
lib_LTLIBRARIES = libmimedecode.la
libmimedecode_la_SOURCES = decode.C header.C multipart.C parser.C \
	../include/mimedecode/client.h ../include/mimedecode/exception.h \
	../include/mimedecode/object.h \
	../include/mimedecode/parser_implementations.h \
	../include/mimedecode/decode.h ../include/mimedecode/field.h \
	../include/mimedecode/parser.h

bin_PROGRAMS = mimedecode

mimedecode_SOURCES = mimedecode.C
mimedecode_LDADD = libmimedecode.la

AM_CPPFLAGS = -I${top_srcdir}/include

