#include "diff.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <stdexcept>

const uint8_t ARG_LIMIT = 3;

const std::vector<std::string> read_file_into_vector(std::string file_name)
{
    std::vector<std::string> file_vector;
    std::string line;
    std::ifstream in_file(file_name);

    if (!in_file) throw std::invalid_argument("failed to open input file");

    while (std::getline(in_file, line))
    {
        file_vector.push_back(line);
    }

    return file_vector;
}

int main(int argc, char ** argv)
{
    if (argc > ARG_LIMIT || argc < ARG_LIMIT) return 1;

    std::string file_name_a (argv[1]);
    std::string file_name_b (argv[2]);
    std::vector<std::string> file_sequence_a = read_file_into_vector(file_name_a);
    std::vector<std::string> file_sequence_b = read_file_into_vector(file_name_b);

    diff comparator(file_sequence_b, file_sequence_a);
    comparator.compute_diff();
}
