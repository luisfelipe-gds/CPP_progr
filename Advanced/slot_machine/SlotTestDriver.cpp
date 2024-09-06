#include "Canvas.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "Slot.h"
using std::cout;
using std::endl;

int main()
{
	
	/* test for canvas */
	/*
	Canvas can1{ 6, 8 };
	cout << "(a)\n" << can1 << "\n";

	can1.write_horizontal(2, 3, "*");
	cout << "(b)\n" << can1 << "\n";

	can1.write_horizontal(3, 3, "**");
	cout << "(c)\n" << can1 << "\n";

	can1.write_horizontal(4, 3, "***");
	cout << "(d)\n" << can1 << "\n";

	can1.write_horizontal(5, 3, "****");
	cout << "(e)\n" << can1 << "\n";

	Canvas can2{ 3, 10 };
	can2.write_horizontal(2, 2, "bonjour");
	cout << "(f)\n" << can2 << "\n";

	Canvas can3{ can1.concat(can2) };
	cout << "(g)\n" << can3 << "\n";

	can3.write_horizontal(5, 10, "hello");
	cout << "(h)\n" << can3 << "\n";

	Canvas can4 = can3.flip_horizontal();
	cout << "(i)\n" << can4 << "\n";

	Canvas can5 = can3.flip_vertical();
	cout << "(j)\n" << can5 << "\n";

	// sets the character displayed at
	// the four corners of the frame.
	can5.setFrame_cor('O');
	cout << "(O)\n" << can5 << "\n";

	// sets the character displayed on
	// the two vertical sides of the frame.
	can5.setFrame_ver('V');
	cout << "(V)\n" << can5 << "\n";

	// sets the character displayed on
	// the two horizontal sides of the frame.
	can5.setFrame_hor('H');
	// writes "byebye" vertically
	can5.write_vertical(1, 8, "byebye");
	cout << "(H)\n" << can5 << "\n";

	Canvas can6{ 3,8,'*'}; // notice that
							// can6’s fill character is ’*’
	can6.write_horizontal(1, 2, "that's");
	can6.write_horizontal(2, 2, "all");
	can6.write_horizontal(3, 2, "folks!");
	cout << "(k)\n" << can6 << "\n";

	can5.clear(); // same as can5.fill(’ ’);
	can5.overlay(can6, 1, 1); // overlays can6 on can5
	cout << "(l)\n" << can5 << "\n";
	can5.overlay(can6, 2, 11); // overlays can6 on can5
	cout << "(m)\n" << can5 << "\n";

	can6.resizeRows(5); // adds 2 rows at the bottom
	cout << "(n)\n" << can6 << "\n";
	*/
	/* test for shapes */
	/*
	Rectangle re{5, 7};

	cout << re << endl;

	cout << re.draw() << endl;

	Rhombus rh{16, 'v', "Ace of diamond"};

	cout << rh << endl;

	cout << rh.draw() << endl;

	AcuteTriangle at{ 17};

	cout << at << endl;

	cout << at.draw() << endl;
	
	RightTriangle rt{ 10, 'L', "Carpenter's Square" };

	cout << rt << endl;

	cout << rt.draw() << endl;
	
	cout << at.draw().concat(rt.draw());

	cout << rt.draw().concat(at.draw());

	cout << re.draw().concat(rh.draw());
	*/
	/* test for slot machine */
	/*
	SlotMachine sm{ 10 };

	sm.run();
	
	return 0;
}
