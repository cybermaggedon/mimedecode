
all install:
	(cd mime; make $@)

test: all

	@echo "*** examples/EXAMPLE1"
	mime/decoder < examples/EXAMPLE1 2>&1 | diff - examples/OUTPUT1; \
	if [ $$? -ne 0 ]; then echo TEST FAILURE; exit 1; fi

	@echo "*** examples/EXAMPLE2"
	mime/decoder < examples/EXAMPLE2 2>&1 | diff - examples/OUTPUT2; \
	if [ $$? -ne 0 ]; then echo TEST FAILURE; exit 1; fi

doxy:
	doxygen docs/doxy.config

