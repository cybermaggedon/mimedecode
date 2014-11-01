
#include <mime/decode.h>

#include <iostream>

#include <stdexcept>

using namespace std;

class my_decoder : public mime::decoder {
public:
    my_decoder() {}
    virtual void object_created(mime::object* object);
    virtual void data_start(mime::object* obj);
    virtual void data(mime::object* obj, const unsigned char *data, 
		      int len);
    virtual void data_end(mime::object* obj);
};

void my_decoder::object_created(mime::object* object)
{

    std::cout << "*** New object type " 
	 << object->type << "/" << object->subtype
	 << endl;

    map<string,mime::field>::iterator i;
    for(i = object->fields.begin();
	i != object->fields.end();
	i++) {
	std::cout << "  " << i->second.key << ": " << i->second.value << endl;
	map<string,string>::iterator j;
	for(j = i->second.attributes.begin();
	    j != i->second.attributes.end();
	    j++) {
	    std::cout << "    " << j->first << ": " << j->second << endl;
	}
    }

}

void my_decoder::data_start(mime::object* object)
{
    std::cout << "*** Data start " 
	 << object->type << "/" << object->subtype
	 << endl;
}

void my_decoder::data(mime::object* object, const unsigned char *data, int len)
{
//    std::cout << "*** Data (" << len << ")" << endl;
    for(int i = 0; i < len; i++)
	std::cout << data[i];
}

void my_decoder::data_end(mime::object* object)
{
    std::cout << "*** Data end " 
	 << object->type << "/" << object->subtype
	 << endl;
}

int main(int argc, char **argv)
{
    
    try {

	my_decoder d;

	char buf[1024];
	int ret;

	while (true) {
	    cin.read(buf, 1024);
	    int ret = cin.gcount();
	    if (ret == 0) break;
	    d.decode(reinterpret_cast<unsigned char*>(buf), ret);
	}

	d.close();

    } catch (exception& e) {
	std::cout << "Exception: " << e.what() << endl;
    }

}

