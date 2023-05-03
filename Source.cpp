#include <iostream>

class Figure {
public:
	Figure() {
		this->sides_count = 0;
		name = "Фигура";
	};

	int get_sides_count() { return this->sides_count; };
	std::string get_name() { return this->name; };
	virtual void print_info(Figure *x) {
		std::cout << x->get_name() << ":" << std::endl;
		std::cout << (x->check() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << x->get_sides_count() << std::endl;
		std::cout << std::endl;
	};
	virtual bool check() { return true; };

protected:

	int sides_count{};
	std::string name{};
};
class Triangle : public Figure {
public:
	Triangle() {};
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->sides_count = 3;
		this->name = "Треугольник";
	}
	void print_info(Figure* x) {
		std::cout << this->get_name() << ":" << std::endl;
		std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << this->get_a() << " b=" << this->get_b() << " c=" << this->get_c() << std::endl;
		std::cout << "Углы: " << "A=" << this->get_A() << " B=" << this->get_B() << " C=" << this->get_C() << std::endl;
		std::cout << std::endl;
	};
	bool check() {
		if ((this->A + this->B + this->C) == 180 && (this->sides_count = 3)) {
			return true;
		}
		else {
			return false;
		}
	};
	int get_a() { return this->a; };
	int get_b() { return this->b; };
	int get_c() { return this->c; };
	int get_A() { return this->A; };
	int get_B() { return this->B; };
	int get_C() { return this->C; };
protected:
	int a{};
	int b{};
	int c{};
	int A{};
	int B{};
	int C{};
};
class RightTriangle : public Triangle {

public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	
	};
	bool check() {
		if ((this->Triangle::check()) && this->C == 90) {
			return true;
		}
		else {
			return false;
		}
	};
};
class IsoscelesTriangle : public Triangle {

public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	};
	bool check() {
		if ((this->Triangle::check()) && (this->a == this->c) && (this->A == this->C)) {
			return true;
		}
		else {
			return false;
		}
	};
};
class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a) :Triangle(a, a, a, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}
	bool check() {
		if ((this->Triangle::check()) && ((this->A == this->B) 
			&& (this->B == this->C)) && ((this->a == this->b) && (this->b == this->c))) {
			return true;
		}
		else {
			return false;
		}

	};
protected:

};
class Quadrangle : public Figure {
public:
	Quadrangle() {};
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->sides_count = 4;
		this->name = "Четырёхугольник";
	}
	void print_info(Figure* x) {
		std::cout << this->get_name() << ":" << std::endl;
		std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
		std::cout << "Стороны: " << "a=" << this->get_a() << " b=" << this->get_b() << " c=" << this->get_c() << " d=" << this->get_d() << std::endl;
		std::cout << "Углы: " << "A=" << this->get_A() << " B=" << this->get_B() << " C=" << this->get_C() << " D=" << this->get_D() << std::endl;
		std::cout << std::endl;
	};
	bool check() {
		if (((this->A + this->B + this->C + this->D) == 360) && sides_count==4) {
			return true;
		}
		else {
			return false;
		}
	};
	int get_a() { return this->a; };
	int get_b() { return this->b; };
	int get_c() { return this->c; };
	int get_d() { return this->d; };
	int get_A() { return this->A; };
	int get_B() { return this->B; };
	int get_C() { return this->C; };
	int get_D() { return this->D; };
protected:
	int a{};
	int b{};
	int c{};
	int d{};
	int A{};
	int B{};
	int C{};
	int D{};

};
class Parallelogram : public Quadrangle {

public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B) {

		this->name = "Параллелограмм";
	};
	bool check() {
		if ((this->Quadrangle::check())  && (this->a == this->c && this->b == this->d) 
			&& (this->A == this->C && this->B == this->D))
		{
			return true;
		}
		else {
			return false;
		}
	};
protected:

};
class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {

		this->name = "Прямоугольник";
	};
	bool check() {
		if (this->Parallelogram::check() && (this->A==90 && this->B==90)) {
			return true;
		}
		else {
			return false;
		}
	};
};
class Square : public Rectangle {

public:
	Square(int a) :Rectangle(a, a) {
		this->name = "Квадрат";
	};
	bool check() {
		if (this->Rectangle::check() && this->a == this->b)
		{
			return true;
		}
		else {
			return false;
		}
	};

};
class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B) :Parallelogram(a, a, A, B) {

		this->name = "Ромб";
	};
	bool check() {
		if (this->Parallelogram::check() && this->a == this->b)
			{
			return true;
		}
		else {
			return false;
		}
	};
};

int main() {
	setlocale(LC_ALL, "Ru");
	Figure fig;
	fig.print_info(&fig);
	Triangle t(10, 20, 30, 50, 60, 70);
	t.print_info(&t);
	RightTriangle rt(10, 20, 30, 50, 60);
	rt.print_info(&rt);
	RightTriangle rtb(10, 20, 30, 50, 40);
	rtb.print_info(&rtb);
	IsoscelesTriangle it(10, 20, 50, 60);
	it.print_info(&it);
	EquilateralTriangle et(30);
	et.print_info(&et);
	Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
	q.print_info(&q);
	Rectangle r(10, 20);
	r.print_info(&r);
	Square s(20);
	s.print_info(&s);
	Parallelogram p(20, 30, 30, 40);
	p.print_info(&p);
	Rhombus rmb(30, 30, 40);
	rmb.print_info(&rmb);
	return 0;
}