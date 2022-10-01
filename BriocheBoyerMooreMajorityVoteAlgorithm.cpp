#include <cstdint>
#include <cassert>

int efjason_number(int *tab, std::size_t len) {
    std::size_t count = 0;
    int votes = 0;
    int ret = -1;

    if (not tab or len == 0)
        return ret;

    for (std::uint32_t cpd = 0; cpd < len; cpd++)
        if (votes == 0) {
            ret = tab[cpd];
            votes = 1;
        } else
            votes += (tab[cpd] == ret) ? 1 : -1;

    for (std::uint32_t cpd = 0; cpd < len; cpd++)
        if (tab[cpd] == ret)
            count++;

    return count > len / 2 ? ret : -1;
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
	    assert(efjason_number((int *)tab, 10) == -1);
    }
    {
        const int tab[] = {3, 2, 3, 10, 3, 12, 3, 3, 45, 3};
        assert(efjason_number((int *)tab, 0) == -1);
	    assert(efjason_number((int *)tab, 10) == 3);
    }
}
