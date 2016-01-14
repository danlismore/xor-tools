//
//  main.cpp
//  xor-tools
//
//  Created by dtl on 12/01/2016.
//  Copyright (c) 2016 LiosMor Security. All rights reserved.
//

#include <cstdlib>
#include "xor-tools.h"

using std::stoul;

string single_byte_xor(string buff, char key)
{
    string out = "";
    size_t len = buff.length();
    for(int i = 0; i < len; i++)
    {
        out += buff[i] ^ key;
    }
    return out;
}

string multi_byte_xor(string buff, string key)
{
    string out = "";
    string key_bytes = "";
    size_t len = buff.length();
    size_t key_len = key.length();
    if(key == "" || buff == "")
    {
        return out;
    }
    if(key_len % 2)
    {
        key += "0";
        std::swap(key.at(key_len), key.at(key_len-1));
    }
    if(key.at(0) == '0' && key.at(1) == 'x')
    {
        key = key.substr(2, key.length());
    }
    key_bytes = key;
    for(int i = 0; i < len; i++)
    {
        if(key_bytes == "")
        {
            key_bytes = key;
        }
        string single_hex = key_bytes.substr(0, 2);
        key_bytes = key_bytes.substr(2, key.length());
        char hex_key = stoul(single_hex, nullptr, 16);
        out += buff.at(i) ^ hex_key;
    }
    return out;
}