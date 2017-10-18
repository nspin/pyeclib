#include <string.h>
#include <sstream>
#include <NTL/ZZ.h>
#include <eclib/mwprocs.h>
#include <eclib/descent.h>
#include "wrapper.h"

bigrational
to_bigrational(char *num_str, char* den_str) {
    NTL::ZZ num_val(NTL::INIT_VAL, num_str);
    NTL::ZZ den_val(NTL::INIT_VAL, den_str);
    return bigrational(num_val, den_val);
}

pair<const char *, const char *>
from_bigrational(bigrational q) {
    std::stringstream num_buf;
    std::stringstream den_buf;
    num_buf << num(q);
    den_buf << den(q);
    return make_pair(num_buf.str().c_str(), den_buf.str().c_str());
}

vector<pair<bigrational, bigrational>>
mwrank(vector<bigrational> ai, long sat_bd, int selmer_only,
    int second_descent, long hlimq, long hlimq0, int naux) {

    two_descent desc(ai, 0, selmer_only, hlimq0, hlimq, naux, second_descent);
    desc.saturate(sat_bd);
    vector<P2Point> basis = desc.getbasis();

    vector<pair<bigrational, bigrational>> v = {};

    for (unsigned int i = 0; i < basis.size(); i++) {
        v.push_back(make_pair(
            bigrational(getX(basis[i]), getZ(basis[i])),
            bigrational(getY(basis[i]), getZ(basis[i]))
        ));
    }

    return v; 
}