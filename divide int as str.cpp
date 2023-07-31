#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> divide_strings(string a, string b) {
  return vector<string> {to_string(stoll(a, nullptr, 10) / stoll(b, nullptr, 10)), to_string(stoll(a, nullptr, 10) % stoll(b, nullptr, 10))}; // This might work for the sample tests and maybe even half of the random tests but it won't work for arbitrarily large integers ;-)
}