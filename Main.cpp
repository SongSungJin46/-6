#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

using namespace std;

int main() {
    vector<Shape*> v; 
    int cmd;

    cout << "�׷��� �������Դϴ�." << endl;
    cout << "1: ����, 2: ����, 3: ��κ���, 4: ����" << endl;

    while (true) {
        cout << "��ɾ� �Է�: ";
        cin >> cmd;

        if (cmd == 1) { 
            int type;
            cout << "������ ���� (1: Line, 2: Circle, 3: Rect): ";
            cin >> type;

            if (type == 1) {
                v.push_back(new Line);
            }
            else if (type == 2) {
                v.push_back(new Circle);
            }
            else if (type == 3) {
                v.push_back(new Rect);
            }
            else {
                cout << "�߸��� �Է��Դϴ�." << endl;
            }
        }
        else if (cmd == 2) {
            if (!v.empty()) {
                cout << "������ ������ �����ϼ��� (1: Line, 2: Circle, 3: Rect): ";
                int type;
                cin >> type;

                bool found = false;
                for (auto it = v.begin(); it != v.end(); ++it) {
                    
                    Line* line = dynamic_cast<Line*>(*it);
                    Circle* circle = dynamic_cast<Circle*>(*it);
                    Rect* rect = dynamic_cast<Rect*>(*it);

                    if ((type == 1 && line) ||
                        (type == 2 && circle) ||
                        (type == 3 && rect)) {
                        delete* it;        
                        v.erase(it);       
                        cout << "������ ���� ���� �Ϸ�." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "�ش��ϴ� ������ �����ϴ�." << endl;
                }
            }
            else {
                cout << "������ ������ �����ϴ�." << endl;
            }
        }
        else if (cmd == 3) { 
            cout << "���� ����� ����:" << endl;
            for (auto shape : v) {
                shape->paint(); 
            }
        }
        else if (cmd == 4) { 
            for (auto shape : v) {
                delete shape; 
            }
            v.clear();
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "�߸��� ����Դϴ�." << endl;
        }
    }

    return 0;
}
