#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mimedecode], [1.1], [mimedecode-general@lists.sourceforge.net])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_SRCDIR([src/header.C])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_TESTDIR([tests])

# Optimiser settings
CXXFLAGS="-O6"

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR

# Libtool
LT_INIT

# Checks for header files.
AC_CHECK_HEADERS([string iostream stdexcept map sys/types.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile tests/atlocal
	include/Makefile])

AC_OUTPUT

