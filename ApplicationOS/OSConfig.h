class OSConfig {
	public:
		static const int WINDOW_WIDTH = 80;
		static const int WINDOW_HEIGHT = 25;
		static const int FIELD_WIDTH = 10;
		static const int FIELD_HEIGHT = 10;
		static const int CELL_VIEW_WIDTH = 2;
		static const int CELL_VIEW_HEIGHT = 2;
		static const int MAX_SHIPS = 10;
		static const int MAX_SHIP_SIZE = 4;
		static const int MIN_BOT_WAITING = 500;
		static const int MAX_BOT_WAITING = 5000;

		static const int FIELD_VIEW_WIDTH = FIELD_WIDTH * CELL_VIEW_WIDTH + 2;
		static const int FIELD_VIEW_HEIGHT = FIELD_HEIGHT * CELL_VIEW_HEIGHT + 2;

		static const int* SHIPS_TYPE();
};