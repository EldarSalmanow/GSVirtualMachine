#include <GS_Reader.h>

namespace GSVirtualMachine::Reader {

    GS_Reader::GS_Reader(GSString filename)
            : _filename(std::move(filename)) {}

    GSByteCode GS_Reader::readFile() {
        GSChar symbol;
        std::ifstream stream;

        try {
            stream.open(_filename, std::ios::binary);

            if (!stream.is_open()) {
                throw Exceptions::GS_Exception("Not found file \'" + _filename + "\'!");
            }

            while (true) {
                stream.read(&symbol, 1);

                if (stream.eof()) {
                    break;
                }

                _input.emplace_back(static_cast<GSByte>(symbol));
            }
        } catch (std::exception &exception) {
            if (stream.is_open()) {
                stream.close();
            }

            throw Exceptions::GS_Exception(exception.what());
        }

    	return _input;
    }

}