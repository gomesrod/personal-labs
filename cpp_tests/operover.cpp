#include <cstdio>
#include <string>

class Vector3D
{
public:
	int x;
	int y;
	int z;
	
	Vector3D(int,int,int);

	Vector3D operator+ (const Vector3D&);
};

int main()
{
	Vector3D vec1 (5, 10, 20);
	Vector3D vec2 (1, 2, 3);
	Vector3D sum = vec1 + vec2;

	Vector3D* cpy1 = &vec1;
	Vector3D cpy2(vec1);

	printf("Vec1 : %d, %d, %d  Pt:%p\n", vec1.x, vec1.y, vec1.z, &vec1);
	printf("Vec2 : %d, %d, %d  Pt:%p\n", vec2.x, vec2.y, vec2.z, &vec2);
	printf("Sum  : %d, %d, %d  Pt:%p\n", sum.x,  sum.y,  sum.z,  &sum);
	printf("Cpy1 : %d, %d, %d  Pt:%p\n", cpy1->x, cpy1->y, cpy1->z, cpy1);
	printf("Cpy2 : %d, %d, %d  Pt:%p\n", cpy2.x, cpy2.y, cpy2.z, &cpy2);

}

Vector3D::Vector3D(int x_, int y_, int z_)
{
	x = x_;
	y = y_;
	z = z_;
}

Vector3D Vector3D::operator+ (const Vector3D& other)
{
	Vector3D res (this->x + other.x, 
			this->y + other.y,
			this->z + other.z);

	printf("Res pointer inside operator: %p\n", &res);
	return res;
}

