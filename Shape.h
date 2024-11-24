#pragma once
#ifndef Shape_h
#define Shape_h

class Shape {
protected:
    virtual void draw() = 0; // 순수 가상 함수
public:
    void paint(); // 공통 paint 함수
    virtual ~Shape() = default; // 가상 소멸자
};

#endif
