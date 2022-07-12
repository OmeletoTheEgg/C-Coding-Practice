
#ifndef OMELETEST6HEADER_H //ifdef guards including this header in multiple files, so it won't get any issues
#define OMELETEST6HEADER_H // makes sure to read the following lines in a single time
#include <string>

class OmeleTest6Header {
public:
    //constructors are mapped here
    OmeleTest6Header();
    OmeleTest6Header(const OmeleTest6Header& orig);
    virtual ~OmeleTest6Header();
    std::string name;
private:

};

#endif /* OMELETEST6HEADER_H */

