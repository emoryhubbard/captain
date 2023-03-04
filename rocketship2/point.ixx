export module point;

export class Point {
public:
	double x;
	double y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point() {
		x = 0;
		y = 0;
	}
	bool equals(Point other) {
		return x == other.x && y == other.y;
	}
};