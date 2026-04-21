
#include <bits/stdc++.h>
#include "visitor.h"
#include "calc.h"
using namespace std;

// For local manual tests we can parse a trivial format: not required by OJ.
// If no input, do nothing.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Construct a simple (1+2)*(3+4) test if run locally without input
    num_node *n1 = new num_node; n1->number = (long long)1;
    num_node *n2 = new num_node; n2->number = (long long)2;
    add_node *a = new add_node; a->lnode = n1; a->rnode = n2;
    num_node *n3 = new num_node; n3->number = (long long)3;
    num_node *n4 = new num_node; n4->number = (long long)4;
    add_node *b = new add_node; b->lnode = n3; b->rnode = n4;
    mul_node *m = new mul_node; m->lnode = a; m->rnode = b;
    calculator calc;
    auto res = calc.visit(m);
    if (auto p = std::any_cast<long long>(&res)) {
        cout << *p << '\n';
    } else if (auto q = std::any_cast<double>(&res)) {
        cout.setf(std::ios::fixed);
        cout << setprecision(10) << *q << '\n';
    }
    return 0;
}
