//
// Created by USUARIO on 5/06/2019.
//

#ifndef INC_0507_FibonacciPROG_H
#define INC_0507_FibonacciPROG_H


class FibonacciProgIterator {
    int curr,curr2;
    friend class FibonacciProg;
    FibonacciProgIterator(int curr,int curr2):
            curr{curr},curr2(curr2) {};
    FibonacciProgIterator(int curr):
            curr{curr} {};
public:
    bool operator==(const FibonacciProgIterator& other) const;
    bool operator!=(const FibonacciProgIterator& other) const;
    int& operator*();
    FibonacciProgIterator& operator++();
    FibonacciProgIterator& operator++(int);
};

class FibonacciProg {
    int start,start2;
    int stop;
public:
    FibonacciProg(int start, int start2, int stop):start{start},
                                                 stop{stop}, start2{start2} {}
    using iterator = FibonacciProgIterator;
    iterator begin() const {
        return FibonacciProg::iterator(start,start2);
    }

    iterator end() const {
        return FibonacciProg::iterator(stop);
    }

};

bool FibonacciProgIterator::operator==(const FibonacciProgIterator&other) const {
    return curr== other.curr;
}

bool FibonacciProgIterator::operator!=(const FibonacciProgIterator &other) const {
    return curr < other.curr;
}

int &FibonacciProgIterator::operator*() {
    return curr;
}

FibonacciProgIterator &FibonacciProgIterator::operator++() {
    int temp=curr2;
    curr2+=curr;
    curr = temp;
    return *this;
}

FibonacciProgIterator& FibonacciProgIterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}


#endif //INC_0506_GEOMETRICPROG_H
