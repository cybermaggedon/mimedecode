
#ifndef PARSER_H
#define PARSER_H

#include <string>

#include <mimedecode/client.h>
#include <mimedecode/object.h>

namespace mime {

    class parser {
      public:
	virtual void parse(unsigned char c) { parse(&c, 1); }
	virtual void parse(const unsigned char* c, unsigned int len) = 0;
	virtual void close() {}
	virtual ~parser() {}
    };

    class object_parser : public parser {
      protected:
	client_interface* client;
	object *obj;
      public:
	object_parser(client_interface* client, object* obj) {
	    this->client = client;
	    this->obj = obj;
	}
    };

    class object_body_parser : public object_parser {
      public:
	object_body_parser(client_interface* client, object* obj) :
	    object_parser(client, obj)
	    {
	    }
    };

}

#endif

