#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class SudokuError : public exception {
protected:
    string msg;
public:
    explicit SudokuError(string  m) : msg(std::move(m)) {}
    ~SudokuError() noexcept override = default;
    virtual void print(ostream& os) const {
        os << msg << endl;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class StreamError : public SudokuError {
public:
    explicit StreamError(const string& m) : SudokuError(m) {}
    void print(ostream& os) const override {
        os << "StreamError: " << msg << endl;
    }
};

class GameLogicError : public SudokuError {
public:
    explicit GameLogicError(const string& m) : SudokuError(m) {}
    void print(ostream& os) const override {
        os << "GameLogicError: " << msg << endl;
    }
};

#endif