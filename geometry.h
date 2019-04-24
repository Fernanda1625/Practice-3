class Point{
		int x, int y;
	public:
		Point();
		Point(int a=0, int b=0):{ x=a; y=b;}
		int getX() {return x;}
		int getY() {return y;}
		void setX(int a){x=a;}
		void setY(int b){y=b;}
};
