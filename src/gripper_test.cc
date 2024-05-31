#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <cassert>

#include "canonical.h"
#include "digraph.h"

using namespace std;

int main(int argc, const char **argv) {
    CanonicalColoring canonical_coloring(0);

    // 2024-05-31 14:28:09,314 -  > Cost: 4; State 1: [<Atom 'room(rooma)'>, <Atom 'room(roomb)'>, <Atom 'gripper(left)'>, <Atom 'gripper(right)'>, <Atom
    // 'ball(ball1)'>, <Atom 'free(left)'>, <Atom 'free(right)'>, <Atom 'at(ball1, rooma)'>, <Atom 'at-robby(roomb)'>] 2024-05-31 14:28:09,314 -  > Cost: 0;
    // State 2: [<Atom 'room(rooma)'>, <Atom 'room(roomb)'>, <Atom 'gripper(left)'>, <Atom 'gripper(right)'>, <Atom 'ball(ball1)'>, <Atom 'free(left)'>, <Atom
    // 'free(right)'>, <Atom 'at-robby(rooma)'>, <Atom 'at(ball1, roomb)'>]

    /**
     * State 1
     */
    // Num nodes: 17
    // Num edges: 28
    // Node colors: [1 1 1 1 1 2 2 3 3 4 5 5 6 7 8 9 10]
    // Undirected edges
    // 0 : [5 13]
    // 1 : [6 14 16]
    // 2 : [7 10]
    // 3 : [8 11]
    // 4 : [9 12 15]
    // 5 : []
    // 6 : []
    // 7 : []
    // 8 : []
    // 9 : []
    // 10 : []
    // 11 : []
    // 12 : [13]
    // 13 : []
    // 14 : []
    // 15 : [16]
    // 16 : []
    Digraph g1(17);
    g1.uadd(0, 5);
    g1.uadd(0, 13);
    g1.uadd(1, 6);
    g1.uadd(1, 14);
    g1.uadd(1, 16);
    g1.uadd(2, 7);
    g1.uadd(2, 10);
    g1.uadd(3, 8);
    g1.uadd(3, 11);
    g1.uadd(4, 9);
    g1.uadd(4, 12);
    g1.uadd(4, 15);
    g1.uadd(12, 13);
    g1.uadd(15, 16);

    assert(g1.num_edges() == 2*14);
    vector<int> alpha = {1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    vector<set<int> > partition = canonical_coloring.calculate(g1, alpha);
    cout << "Canonical equitable partition: " << partition << endl;
    cout << "Histogram: " << CanonicalColoring::histogram(canonical_coloring.partition()) << endl;

    /**
     * State 2
     */
    // Num nodes: 17
    // Num edges: 28
    // Node colors: [1 1 1 1 1 2 2 3 3 4 5 5 6 7 8 9 10]
    // Undirected edges
    // 0 : [5 12]
    // 1 : [6 14 16]
    // 2 : [7 10]
    // 3 : [8 11]
    // 4 : [9 13 15]
    // 5 : []
    // 6 : []
    // 7 : []
    // 8 : []
    // 9 : []
    // 10 : []
    // 11 : []
    // 12 : []
    // 13 : [14]
    // 14 : []
    // 15 : [16]
    // 16 : []

    Digraph g2(17);
    g2.uadd(0, 5);
    g2.uadd(0, 12);
    g2.uadd(1, 6);
    g2.uadd(1, 14);
    g2.uadd(1, 16);
    g2.uadd(2, 7);
    g2.uadd(2, 10);
    g2.uadd(3, 8);
    g2.uadd(3, 11);
    g2.uadd(4, 9);
    g2.uadd(4, 13);
    g2.uadd(4, 15);
    g2.uadd(13, 14);
    g2.uadd(15, 16);
    assert(g2.num_edges() == 2*14);
    vector<int> beta = {1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    partition = canonical_coloring.calculate(g2, beta);
    cout << "Canonical equitable partition: " << partition << endl;
    cout << "Histogram: " << CanonicalColoring::histogram(canonical_coloring.partition()) << endl;

    return 0;
}

