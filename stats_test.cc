#include "stats.h"
#include <cassert>
#include <cmath>

int main() {
    assert(std::abs(PropTest(14, 100, 20, 100) - 0.25870176105718945) < 1e-9);
    assert(PropTest(0, 0, 0, 0) == -1);
    return 0;
}
