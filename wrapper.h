#include <vector>
#include <eclib/bigrat.h>

bigrational
to_bigrational(char *num_str, char* den_str);

pair<const char *, const char *>
from_bigrational(bigrational q);

std::vector<std::pair<bigrational, bigrational>>
mwrank(vector<bigrational> ai, long sat_bd, int selmer_only,
    int second_descent, long hlimq, long hlimq0, int naux);