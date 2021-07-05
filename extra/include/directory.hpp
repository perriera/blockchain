#ifndef _DIRECTORY_HPP
#define _DIRECTORY_HPP

#include <iostream>
#include <vector>
#include "Definitions.hpp"

//
// simplest crc16 c++ implementation
// https://github.com/jpralves/crc16
//

typedef std::string Path;
typedef std::vector<std::string> Listing;

interface DirectoryInterface {
    virtual const Path& path() const pure;
    virtual const Listing& listing() const pure;
};

class Directory implements DirectoryInterface
{
public:
	Directory(const Path& path);

    virtual const Path& path() const { return _path; }
	virtual const Listing& listing() const { return _listing; }

private:
	Path _path;
    Listing _listing;
};


#endif // _DIRECTORY_HPP
