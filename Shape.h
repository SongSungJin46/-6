#pragma once
#ifndef Shape_h
#define Shape_h

class Shape {
protected:
    virtual void draw() = 0; // ���� ���� �Լ�
public:
    void paint(); // ���� paint �Լ�
    virtual ~Shape() = default; // ���� �Ҹ���
};

#endif
