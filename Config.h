class Config{
	public:
		static const int FIELD_WIDTH = 10;
		static const int FIELD_HEIGHT = 10;
		static const int CELL_WIDTH = 2;
		static const int CELL_HEIGHT = 2;
		static const int MAX_SHIPS = 10;
		static const int MAX_SHIP_SIZE = 4;

		static const int FIELD_WIDTH_SIZE = FIELD_WIDTH * CELL_WIDTH + 2;
		static const int FIELD_HEIGHT_SIZE = FIELD_HEIGHT * CELL_HEIGHT + 2;
};