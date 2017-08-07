#include "Cell.h"

void Cell::draw() {
	Console* console = Console::Instance();

	console->setColor(textColor_, backgroundColor_);

	console->fillSquare(" ", width_, height_, x_, y_);

	console->setColor(console->White, console->Black);
}