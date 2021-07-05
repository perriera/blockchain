#include <iostream>
#include <fstream>
#include "directory.hpp"

using namespace std;

//
// simplest crc64 c++ implementation
// https://gist.github.com/timepp
//

Directory::Directory(const Path &path) : _path(path)
{
    string listing_file = "/tmp/listing.txt";
    string cmd = "ls " + _path + ">" + listing_file;
    system(cmd.c_str());
    ifstream listing_stream(listing_file);
    Listing listing;
    while (listing_stream.good())
    {
        string listing_line;
        listing_stream >> listing_line;
        if (listing_line.size() > 0)
        {
            listing_line = path + "/" + listing_line;
            listing.push_back(listing_line);
        }
    }
    this->_listing = listing;
};
