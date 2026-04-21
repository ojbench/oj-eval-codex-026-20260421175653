
#pragma once

#include "visitor.h"

struct calculator : visitor {
    std::any visit_num(num_node *n) override {
        return n->number;
    }
    std::any visit_add(add_node *n) override {
        auto l = visit(n->lnode);
        auto r = visit(n->rnode);
        if (is_double(l) || is_double(r)) {
            return std::any(as_double(l) + as_double(r));
        } else {
            return std::any(as_ll(l) + as_ll(r));
        }
    }
    std::any visit_sub(sub_node *n) override {
        auto l = visit(n->lnode);
        auto r = visit(n->rnode);
        if (is_double(l) || is_double(r)) {
            return std::any(as_double(l) - as_double(r));
        } else {
            return std::any(as_ll(l) - as_ll(r));
        }
    }
    std::any visit_mul(mul_node *n) override {
        auto l = visit(n->lnode);
        auto r = visit(n->rnode);
        if (is_double(l) || is_double(r)) {
            return std::any(as_double(l) * as_double(r));
        } else {
            return std::any(as_ll(l) * as_ll(r));
        }
    }
    std::any visit_div(div_node *n) override {
        auto l = visit(n->lnode);
        auto r = visit(n->rnode);
        if (is_double(l) || is_double(r)) {
            return std::any(as_double(l) / as_double(r));
        } else {
            return std::any(as_ll(l) / as_ll(r));
        }
    }

    ~calculator() override = default;
private:
    static bool is_double(const std::any &v) {
        return std::any_cast<const double>(&v) != nullptr;
    }
    static bool is_ll(const std::any &v) {
        return std::any_cast<const long long>(&v) != nullptr;
    }
    static double as_double(const std::any &v) {
        if (auto p = std::any_cast<const double>(&v)) return *p;
        if (auto q = std::any_cast<const long long>(&v)) return static_cast<double>(*q);
        return 0.0;
    }
    static long long as_ll(const std::any &v) {
        if (auto q = std::any_cast<const long long>(&v)) return *q;
        if (auto p = std::any_cast<const double>(&v)) return static_cast<long long>(*p);
        return 0;
    }
};
