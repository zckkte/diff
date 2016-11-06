#include "diff.hpp"

diff::diff(const std::vector<std::string> sequence_a, 
    const std::vector<std::string> sequence_b)
{
    this->sequence_a = sequence_a;
    this->sequence_b = sequence_b;
    this->lcs_table = diff::lcs_length(sequence_a, sequence_b);
}

const std::vector<std::vector<int32_t>> 
diff::lcs_length(const std::vector<std::string>& sequence_a, 
    const std::vector<std::string>& sequence_b)
{
    std::vector<std::vector<int32_t>> lcs_table(sequence_a.size(), 
        std::vector<int32_t>(sequence_b.size(), 0));
    for (int32_t i = 1; i < sequence_a.size(); i++)
    {
        for (int32_t j = 1; j < sequence_b.size(); j++)
        {
            lcs_table[i][j] = (sequence_a[i].compare(sequence_b[j]) != 0) 
                ? std::max(lcs_table[i][j - 1], lcs_table[i - 1][j])
                : lcs_table[i - 1][j - 1] + 1;
        }
    }

    return lcs_table;
}

void diff::compute_diff()
{
    (void) compute_diff_rec(this->sequence_a.size() - 1, 
            this->sequence_b.size() - 1);
}

void diff::compute_diff_rec(int32_t curr_index_a, int32_t curr_index_b)
{
    if (curr_index_a >= 0 && curr_index_b >= 0
        && this->sequence_a[curr_index_a].compare(this->sequence_b[curr_index_b]) == 0)
    {
        compute_diff_rec(curr_index_a - 1, curr_index_b - 1);
        std::cout << "  " + this->sequence_a[curr_index_a];
    }
    else if (curr_index_b > 0 && (curr_index_a == 0 
        || this->lcs_table[curr_index_a][curr_index_b - 1]
            >= this->lcs_table[curr_index_a - 1][curr_index_b]))
    {
        compute_diff_rec(curr_index_a, curr_index_b - 1);
        std::cout << "+" + this->sequence_b[curr_index_b];
    }
    else if (curr_index_a > 0 && (curr_index_b == 0 
        || this->lcs_table[curr_index_a][curr_index_b - 1]
            < this->lcs_table[curr_index_a - 1][curr_index_b]))
    {
        compute_diff_rec(curr_index_a - 1, curr_index_b);
        std::cout << "-" + this->sequence_a[curr_index_a];
    }

    std::cout << std::endl;
}

