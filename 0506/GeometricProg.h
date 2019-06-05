//
// Created by USUARIO on 5/06/2019.
//

#ifndef INC_0506_GEOMETRICPROG_H
#define INC_0506_GEOMETRICPROG_H


class GeometricProgIterator {
    int curr;
    int step;
    friend class GeometricProg;
    GeometricProgIterator(int curr, int step):
            curr{curr}, step{step} {}
public:
    bool operator==(const GeometricProgIterator& other) const;
    bool operator!=(const GeometricProgIterator& other) const;
    int& operator*();
    GeometricProgIterator& operator++();
    GeometricProgIterator& operator++(int);
};

class GeometricProg {
    int start;
    int stop;
    int step;
public:
    GeometricProg(int step, int stop):start{1},
                               stop{stop}, step{step} {}
    GeometricProg(int start, int stop, int step):start{start},
                                         stop{stop}, step{step} {}
    using iterator = GeometricProgIterator;
    iterator begin() const {
        return GeometricProg::iterator(start, step);
    }

    iterator end() const {
        return GeometricProg::iterator(stop, step);
    }

};

bool GeometricProgIterator::operator==(const GeometricProgIterator&other) const {
    return curr == other.curr;
}

bool GeometricProgIterator::operator!=(const GeometricProgIterator &other) const {
    return curr < other.curr;
}

int &GeometricProgIterator::operator*() {
    return curr;
}

GeometricProgIterator &GeometricProgIterator::operator++() {
    curr *= step;
    return *this;
}

GeometricProgIterator& GeometricProgIterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}


#endif //INC_0506_GEOMETRICPROG_H
