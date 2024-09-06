#include <iostream>
#include <vector>
#include <memory>
#include "Canvas.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "Slot.h"


using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::make_unique;

void testCanvas() {
    cout << "\n--- Beginning Canvas Tests ---\n\n";
    Canvas can1{6, 8};
    cout << "Canvas can1{6, 8};\n";
    cout << "(a)\n" << can1 << "\n";

    can1.write_horizontal(2, 3, "*");
    cout << "can1.write_horizontal(2, 3, \"*\");\n";
    cout << "(b)\n" << can1 << "\n";

    can1.write_horizontal(3, 3, "**");
    cout << "can1.write_horizontal(3, 3, \"**\");\n";
    cout << "(c)\n" << can1 << "\n";

    can1.write_horizontal(4, 3, "***");
    cout << "can1.write_horizontal(4, 3, \"***\");\n";
    cout << "(d)\n" << can1 << "\n";

    can1.write_horizontal(5, 3, "****");
    cout << "can1.write_horizontal(5, 3, \"****\");\n";
    cout << "(e)\n" << can1 << "\n";

    Canvas can2{3, 10};
    cout << "Canvas can2{3, 10};\n";
    can2.write_horizontal(2, 2, "bonjour");
    cout << "can2.write_horizontal(2, 2, \"bonjour\");\n";
    cout << "(f)\n" << can2 << "\n";

    Canvas can3{can1.concat(can2)};
    cout << "Canvas can3{can1.concat(can2)};\n";
    cout << "(g)\n" << can3 << "\n";

    can3.write_horizontal(5, 10, "hello");
    cout << "can3.write_horizontal(5, 10, \"hello\");\n";
    cout << "(h)\n" << can3 << "\n";

    Canvas can4 = can3.flip_horizontal();
    cout << "Canvas can4 = can3.flip_horizontal();\n";
    cout << "(i)\n" << can4 << "\n";

    Canvas can5 = can3.flip_vertical();
    cout << "Canvas can5 = can3.flip_vertical();\n";
    cout << "(j)\n" << can5 << "\n";

    // sets the character displayed at the four corners of the frame.
    can5.setFrame_cor('O');
    cout << "can5.setFrame_cor('O');\n";
    cout << "(O)\n" << can5 << "\n";

    // sets the character displayed on the two vertical sides of the frame.
    can5.setFrame_ver('V');
    cout << "can5.setFrame_ver('V');\n";
    cout << "(V)\n" << can5 << "\n";

    // sets the character displayed on the two horizontal sides of the frame.
    can5.setFrame_hor('H');
    cout << "can5.setFrame_hor('H');\n";

    // writes "byebye" vertically
    can5.write_vertical(1, 8, "byebye");
    cout << "can5.write_vertical(1, 8, \"byebye\");\n";
    cout << "(H)\n" << can5 << "\n";

    Canvas can6{3, 8, '*'};  // notice that can6’s fill character is '*'
    cout << "Canvas can6{3, 8, '*'};\n";
    can6.write_horizontal(1, 2, "that's");
    cout << "can6.write_horizontal(1, 2, \"that's\");\n";
    can6.write_horizontal(2, 2, "all");
    cout << "can6.write_horizontal(2, 2, \"all\");\n";
    can6.write_horizontal(3, 2, "folks!");
    cout << "can6.write_horizontal(3, 2, \"folks!\");\n";
    cout << "(k)\n" << can6 << "\n";

    can5.clear();  // same as can5.fill(' ');
    cout << "can5.clear();\n";
    can5.overlay(can6, 1, 1);  // overlays can6 on can5
    cout << "can5.overlay(can6, 1, 1);\n";
    cout << "(l)\n" << can5 << "\n";

    can5.overlay(can6, 2, 11);  // overlays can6 on can5
    cout << "can5.overlay(can6, 2, 11);\n";
    cout << "(m)\n" << can5 << "\n";
}

void testShapes() {

    Rectangle rect{5, 7};
    cout << rect << endl;

    Rhombus ace{16, 'v', "Ace of diamond"};
    cout << ace.toString() << endl;
  
    AcuteTriangle at{17};
    cout << at << endl;
 

    RightTriangle rt{10, 'L', "Carpenter’s square"};
    cout << rt << endl;

    Canvas rectCan{rect.draw()};
    cout << "Canvas rectCan{rect.draw()};\n";
    cout << rectCan << endl;

    Canvas aceCan{ace.draw()};
    cout << "Canvas aceCan{ace.draw()};\n";
    cout << aceCan << endl;

    at.setPen('^');
    cout << "at.setPen('^');\n";
    Canvas atCan{at.draw()};
    cout << "Canvas atCan{at.draw()};\n";
    cout << atCan << endl;

    Canvas rtCan{rt.draw()};
    cout << "Canvas rtCan{rt.draw()};\n";
    cout << rtCan << endl;

    // Flipping canvas objects w/ shapes
    rt.setPen('O');
    Canvas rtQuadrant_1{rt.draw()};
    cout << rtQuadrant_1 << endl;

    Canvas rtQuadrant_2{rtQuadrant_1.flip_horizontal()};
    cout << rtQuadrant_2 << endl;

    Canvas rtQuadrant_3{rtQuadrant_2.flip_vertical()};
    cout << rtQuadrant_3 << endl;

    Canvas rtQuadrant_4{rtQuadrant_3.flip_horizontal()};
    cout << rtQuadrant_4 << endl;

    // create a vector of smart pointers to Shape
    vector<unique_ptr<Shape>> shapeVec;
    cout << "vector<unique_ptr<Shape>> shapeVec;\n";
    
    // Next, add some shapes to shapeVec
    shapeVec.push_back(make_unique<Rectangle>(5, 7));
    cout << "shapeVec.push_back(make_unique<Rectangle>(5, 7));\n";
    shapeVec.push_back(make_unique<Rhombus>(16, 'v', "Ace"));
    cout << "shapeVec.push_back(make_unique<Rhombus>(16, 'v', \"Ace\"));\n";
    shapeVec.push_back(make_unique<AcuteTriangle>(17));
    cout << "shapeVec.push_back(make_unique<AcuteTriangle>(17));\n";
    shapeVec.push_back(make_unique<RightTriangle>(10, 'L'));
    cout << "shapeVec.push_back(make_unique<RightTriangle>(10, 'L'));\n";
    
    for (const auto& shp : shapeVec) {
        cout << "cout << shp->draw() << endl;\n";
        cout << shp->draw() << endl;
    }
}

void testSlots(){
    SlotMachine slotMachine;
    slotMachine.run();
}

int main() {

    testShapes(); 
    testCanvas();
    testSlots();
    return 0;
}
