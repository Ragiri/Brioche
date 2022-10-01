#include <unordered_map>
#include <algorithm>
#include <cstdint>
#include <cassert>

int efjason_number(int *tab, std::size_t len) {
    std::unordered_map<int, double> percentages;
    int tmp = 0;

    if (len == 0)
        return -1;

    for (std::uint32_t cpd = 0; cpd < len; cpd++)
        percentages[tab[cpd]] += 100 / len;

    tmp = percentages.begin()->first;
    for (const auto &[k, v] : percentages) {
        if (v > percentages.at(tmp))
            tmp = k;
    }

    return percentages.at(tmp) >= 50.0 ? tmp : -1;
}

int main(void) {
    {
        const int tab[] = {1, 2, 3, 10, 11, 12, 3, 44, 45, 3};
        assert(efjason_number((int *)tab, 0) == -1);
	    assert(efjason_number((int *)tab, 10) == -1);
    }
    {
        const int tab[] = {3, 2, 3, 10, 3, 12, 3, 44, 45, 3};
        assert(efjason_number((int *)tab, 0) == -1);
	    assert(efjason_number((int *)tab, 10) == 3);
    }
}
