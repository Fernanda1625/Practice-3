//Ejercicio 3.1

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

//Ejercicio 4.1

class PointArray{
		int size;
		Point *points;
		void resize(int size);
	
	public:
		PointArray();
		PointArray(const Point pts[], const int size);
		PointArray(const PointArray &pv);
		~PointArray();
		
		void clear();
		int getSize() const { return size;}
		void push_back(const Point &p);
		void insert (const int pos , const Point &p);
		void remove (const int pos);
		Point *get(const int pos);
		const Point *get(const int pos) const;
};

//Ejercicio 5.1.1

class Polygon {
	protected:
		static int numPolygons;
		PointArray points;
	public:
		Polygon (const PointArray &pa);
		Polygon (const Point points[], const int numPoints);
		virtual double area() const = 0;
		static int getNumPolygons() { return numPolygons;}
		int getNumSides() const { return points.getSize();}
		const PointArray() *getPoints() const { return &points;}
		~Polygon() { --numPolygons;}
};

//Ejercicio 5.2.1

class Rectangle : public Polygon {
	public:
		Rectangle(const Point &a, const Point &b);
		Rectangle(const a, const int b, const int c, const int d);
		virtual doble area() const;
};


		
