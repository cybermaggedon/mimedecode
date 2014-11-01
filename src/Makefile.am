
lib_LTLIBRARIES = libmimedecode.la
libmimedecode_la_SOURCES = decode.C header.C multipart.C parser.C \
	mime/client.h mime/exception.h mime/object.h \
	mime/parser_implementations.h mime/decode.h mime/field.h \
	mime/parser.h

bin_PROGRAMS = mimedecode

mimedecode_SOURCES = mimedecode.C
mimedecode_LDADD = libmimedecode.la

AM_CPPFLAGS = -I${top_srcdir}/include

