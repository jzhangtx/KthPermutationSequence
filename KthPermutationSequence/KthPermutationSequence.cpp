// KthPermutationSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

void GetPermutations(std::string& str, size_t index, std::vector<std::string>& result)
{
    if (index == str.size())
    {
        result.push_back(str);
        return;
    }

    for (size_t j = index; j < str.size(); ++j)
    {
        std::swap(str[j], str[index]);
        GetPermutations(str, index + 1, result);
        std::swap(str[j], str[index]);
    }
}

std::string GetKthPermutation(int n, int k)
{
    if (n > 62)
        throw std::runtime_error("n is too big! It should be 62 or smaller!");

    std::string str(n, '1');
    for (unsigned char i = 0; i < static_cast<unsigned char>(n); ++i)
    {
        if (i < 10)
            str[i] += i;
        else if (i < 36)
            str[i] = 'a' + i - 10;
        else
            str[i] = 'A' + i - 36;
    }

    std::vector<std::string> v;
    GetPermutations(str, 0, v);
    if (v.size() > static_cast<size_t>(k))
        return v[k - 1];

    return "";
}

int main()
{
    while (true)
    {
        std::cout << "Enter number: ";
        int n;
        std::cin >> n;
        if (n == 0)
            break;

        std::cout << "Which permutation you want? ";
        int k;
        std::cin >> k;

        std::cout << GetKthPermutation(n, k) << std::endl;
    }
}
