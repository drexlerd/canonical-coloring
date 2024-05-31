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

    // 2024-05-31 17:30:09,395 -  > Cost: 4; State 1: [<Atom 'room(rooma)'>, <Atom 'room(roomb)'>, <Atom 'gripper(left)'>, <Atom 'gripper(right)'>, <Atom 'ball(ball1)'>, <Atom 'free(left)'>, <Atom 'free(right)'>, <Atom 'at(ball1, rooma)'>, <Atom 'at-robby(roomb)'>]
    // 2024-05-31 17:30:09,395 -  > Cost: 0; State 2: [<Atom 'room(rooma)'>, <Atom 'room(roomb)'>, <Atom 'gripper(left)'>, <Atom 'gripper(right)'>, <Atom 'ball(ball1)'>, <Atom 'free(left)'>, <Atom 'free(right)'>, <Atom 'at(ball1, roomb)'>, <Atom 'at-robby(roomb)'>]

    /**
     * State 1
     */
    //Num nodes: 7
    //Num edges: 4
    //Node colors: [1 2 3 3 4 5 6]
    //Edge colors: [0 0 0 0]
    //Outbound adjacent:
    //    0 : []
    //    1 : []
    //    2 : []
    //    3 : []
    //    4 : [5 6]
    //    5 : [0]
    //    6 : [1]
    Digraph g1(7);
    g1.add(4, 5);
    g1.add(4, 6);
    g1.add(5, 0);
    g1.add(6, 1);


    assert(g1.num_edges() == 4);
    vector<int> alpha = {1, 2, 3, 3, 4, 5, 6};
    vector<set<int> > partition = canonical_coloring.calculate(g1, alpha);
    cout << "Canonical equitable partition: " << partition << endl;
    cout << "Histogram: " << CanonicalColoring::histogram(canonical_coloring.partition()) << endl;

    /**
     * State 2
     */
    //Num nodes: 7
    //Num edges: 4
    //Node colors: [1 2 3 3 4 5 6]
    //Edge colors: [0 0 0 0]
    // Directed edges
    //    0 : []
    //    1 : []
    //    2 : []
    //    3 : []
    //    4 : [5,6]
    //    5 : [1]
    //    6 : [1]

    Digraph g2(7);
    g2.add(4, 5);
    g2.add(4, 6);
    g2.add(5, 1);
    g2.add(6, 1);

    assert(g2.num_edges() == 4);
    vector<int> beta = {1, 2, 3, 3, 4, 5, 6};
    partition = canonical_coloring.calculate(g2, beta);
    cout << "Canonical equitable partition: " << partition << endl;
    cout << "Histogram: " << CanonicalColoring::histogram(canonical_coloring.partition()) << endl;

    return 0;
}

