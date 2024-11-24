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

    cout << "그래픽 편집기입니다." << endl;
    cout << "1: 삽입, 2: 삭제, 3: 모두보기, 4: 종료" << endl;

    while (true) {
        cout << "명령어 입력: ";
        cin >> cmd;

        if (cmd == 1) { 
            int type;
            cout << "삽입할 도형 (1: Line, 2: Circle, 3: Rect): ";
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
                cout << "잘못된 입력입니다." << endl;
            }
        }
        else if (cmd == 2) {
            if (!v.empty()) {
                cout << "삭제할 도형을 선택하세요 (1: Line, 2: Circle, 3: Rect): ";
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
                        cout << "선택한 도형 삭제 완료." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "해당하는 도형이 없습니다." << endl;
                }
            }
            else {
                cout << "삭제할 도형이 없습니다." << endl;
            }
        }
        else if (cmd == 3) { 
            cout << "현재 저장된 도형:" << endl;
            for (auto shape : v) {
                shape->paint(); 
            }
        }
        else if (cmd == 4) { 
            for (auto shape : v) {
                delete shape; 
            }
            v.clear();
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 명령입니다." << endl;
        }
    }

    return 0;
}
