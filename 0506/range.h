

//
// Created by rrivas on 05/06/19.
//

#ifndef RANGO_RANGE_H
#define RANGO_RANGE_H

class ArithmethicProgIterator {
    int curr;
    int step;
    friend class ArithmeticProg;
    ArithmethicProgIterator(int curr, int step):
            curr{curr}, step{step} {}
public:
    bool operator==(const ArithmethicProgIterator& other) const;
    bool operator!=(const ArithmethicProgIterator& other) const;
    int& operator*();
    ArithmethicProgIterator& operator++();
    ArithmethicProgIterator& operator++(int);
};


class ArithmeticProg {
    int start;
    int stop;
    int step;
public:
    ArithmeticProg(int stop):start{0}, stop{stop}, step{1} {}
    ArithmeticProg(int start, int stop):start{start},
                               stop{stop}, step{1} {}
    ArithmeticProg(int start, int stop, int step):start{start},
                                         stop{stop}, step{step} {}
    using iterator = ArithmethicProgIterator;
    iterator begin() const {
        return ArithmeticProg::iterator(start, step);
    }

    iterator end() const {
        return ArithmeticProg::iterator(stop, step);
    }

};

bool ArithmethicProgIterator::operator==(const ArithmethicProgIterator&other) const {
    return curr == other.curr;
}

bool ArithmethicProgIterator::operator!=(const ArithmethicProgIterator &other) const {
    return curr < other.curr;
}

int &ArithmethicProgIterator::operator*() {
    return curr;
}

ArithmethicProgIterator &ArithmethicProgIterator::operator++() {
    curr += step;
    return *this;
}

ArithmethicProgIterator& ArithmethicProgIterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}

#endif //RANGO_RANGE_H