//
//  xor-tools.h
//  xor-tools
//
//  Created by dtl on 12/01/2016.
//  Copyright (c) 2016 LiosMor Security. All rights reserved.
//

#ifndef xor_tools_xor_tools_h
#define xor_tools_xor_tools_h

#include <string>

using std::string;

string single_byte_xor(string buff, char key);
string multi_byte_xor(string buff, string key);

#endif
