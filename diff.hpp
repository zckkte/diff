#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class diff
{
    private:
        std::vector<std::vector<int32_t>> lcs_table;
        std::vector<std::string> sequence_a;
        std::vector<std::string> sequence_b;

        void compute_diff_rec(int32_t index_a, int32_t index_b);
        const std::vector<std::vector<int32_t>> 
            lcs_length(const std::vector<std::string>& sequence_a,
                const std::vector<std::string>& sequence_b);

    public:
        diff(const std::vector<std::string> sequence_a,
                const std::vector<std::string> sequence_b);
        void compute_diff();
};
