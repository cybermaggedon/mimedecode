
#include <mimedecode/decode.h>
#include <mimedecode/exception.h>
#include <mimedecode/field.h>
#include <mimedecode/object.h>
#include <mimedecode/parser.h>

#include <stdexcept>
#include <sstream>
#include <cctype>

using namespace mime;

void decoder::decode(const unsigned char* buf, unsigned int len)
{

    if (!p)
	p = parser_factory::generic(this, obj);

    p->parse(buf, len);

}
