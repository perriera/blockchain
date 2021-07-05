#ifndef _STRING_SUPPORT_HPP
#define _STRING_SUPPORT_HPP

#include <algorithm> 
#include <string> 
#include <cctype>
#include <locale>
#include <vector>
#include <sstream>
#include <deque>

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(const std::string& s) {
    auto dup = s;
    ltrim(dup);
    return dup;
}

// trim from end (copying)
static inline std::string rtrim_copy(const std::string& s) {
    auto dup = s;
    rtrim(dup);
    return dup;
}

// trim from both ends (copying)
static inline std::string trim_copy(const std::string& s) {
    auto dup = s;
    trim(dup);
    return dup;
}

std::deque<std::string> split (const std::string &s, char delim);
std::string replace_all (const std::string &s, char a, char b);
std::string remove_all (const std::string &s, char a);
std::string replace_all(std::string str, const std::string& from, const std::string& to);

#include <sstream>

// cout << plusone(42);
template<typename T>
std::string plusone(T const& t) {
    std::ostringstream oss;
    oss << (t + 1);
    return oss.str();
}

#endif // _STRING_SUPPORT_HPP
