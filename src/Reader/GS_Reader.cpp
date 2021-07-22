#include <GS_Reader.h>

namespace GSVirtualMachine {

    GS_Reader::GS_Reader(GSString filename)
            : _filename(std::move(filename)) {}

    GSByteCode GS_Reader::readFile() {
        GSByte symbol;
        std::ifstream stream;

        try {
            stream.open(_filename, std::ios::binary);

            if (!stream.is_open()) {
                throw Exceptions::GS_Exception("Not found file \'" + _filename + "\'!");
            }

            while (true) {
                stream >> symbol;

                if (stream.eof()) {
                    break;
                }

                _input.emplace_back(symbol);
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