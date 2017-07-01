// Copyright 2017 Maxim Doronin

#ifndef MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_
#define MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_

#include <string>
#include <vector>

class Function {
 public:
    explicit Function(std::vector<float> koefs);
    virtual ~Function() {}
    virtual float f(float x) const = 0;
    virtual float df(float x) const = 0;
    virtual float d2f(float x) const = 0;
 protected:
    std::vector<float> koefs_;
    void generateThrow(std::string type) const;
    void checkKoefs(unsigned int neededNumberOfKoefs) const;
};

class Polynomial2Degree : public Function {
 public:
    explicit Polynomial2Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual ~Polynomial2Degree() {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Polynomial3Degree : public Function {
 public:
    explicit Polynomial3Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual ~Polynomial3Degree() {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Polynomial4Degree : public Function {
 public:
    explicit Polynomial4Degree(std::vector<float> koefs) : Function(koefs) {}
    virtual ~Polynomial4Degree() {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

class Exponent : public Function {
 public:
    explicit Exponent(std::vector<float> koefs) : Function(koefs) {}
    virtual ~Exponent() {}
    virtual float f(float x) const;
    virtual float df(float x) const;
    virtual float d2f(float x) const;
};

#endif  // MODULES_ROOT_FINDER_INCLUDE_FUNCTIONS_H_
