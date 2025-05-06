#include <vector>
#include <cmath>

// Function to check if the puzzle is solvable with the randomly generated sequence of numbers
bool checkSolvable(std::vector<short int> &sequence)
{
    // Calculate number of inversions
    // Using the slower method, as the grid size is small (N = 16)
    unsigned int inversions{}, row{};
    std::size_t N{sequence.size()};

    for(std::size_t i = 0; i < N; ++i)
    {

        if(sequence[i] == 0)
        {
            // row is counted from bottom to top (indexed from 1)
            row = 4 - (i / 4);
            continue;
        }

        for(std::size_t j = i + 1; j < N; ++j)
        {
            if(sequence[i] > sequence[j] && sequence[j] != 0)
                ++inversions;
        }
    }

    // if row is even => number of inversions must be odd
    if(row % 2 == 0) return (inversions % 2 != 0);

    // else number of inversions must be even
    return (inversions % 2 == 0);
}